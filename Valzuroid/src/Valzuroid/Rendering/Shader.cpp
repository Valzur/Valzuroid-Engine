#include "vzpch.h"
#include "Shader.h"
#include "Valzuroid/Application.h"

#include <fstream>
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Valzuroid
{
	Shader::Shader(const std::string& filePath)
		: m_FilePath(filePath), m_RendererID(0)
	{
		ShaderProgramSource source = Parse(filePath);
		m_RendererID = Shader::Create(source.VertexSource, source.FragmentSource);
	}

	Shader::~Shader()
	{
		glDeleteProgram(m_RendererID);
	}

	ShaderProgramSource Shader::Parse(const std::string& filePath)
	{
		std::ifstream stream(filePath);

		enum class ShaderType
		{
			NONE = -1, VERTEX = 0, FRAGMENT = 1
		};

		std::string line;
		std::stringstream ss[2];
		ShaderType type = ShaderType::NONE;
		while (getline(stream, line))
		{
			if (line.find("vertex") != std::string::npos)
			{
				type = ShaderType::VERTEX;
			}
			else if (line.find("fragment") != std::string::npos)
			{
				type = ShaderType::FRAGMENT;
			}
			else
			{
				ss[(int)type] << line << "\n";
			}
		}

		return { ss[0].str(), ss[1].str() };
	}

	unsigned int Shader::Create(const std::string& vertexShader, const std::string& fragmentShader)
	{
		unsigned int program = glCreateProgram();
		unsigned int vs = Compile(GL_VERTEX_SHADER, vertexShader);
		unsigned int fs = Compile(GL_FRAGMENT_SHADER, fragmentShader);

		glAttachShader(program, vs);
		glAttachShader(program, fs);
		glLinkProgram(program);
		glValidateProgram(program);

		glDeleteShader(vs);
		glDeleteShader(fs);

		return program;
	}

	unsigned int Shader::Compile(unsigned int type, const std::string& source)
	{
		unsigned int id = glCreateShader(type);
		const char* src = source.c_str();
		glShaderSource(id, 1, &src, NULL);
		glCompileShader(id);

		int result;
		glGetShaderiv(id, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE)
		{
			int length;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
			char* message = (char*)alloca(length * sizeof(char));
			glGetShaderInfoLog(id, length, &length, message);
			VZ_CORE_INFO(message);

			glDeleteShader(id);
			return 0;
		}

		return id;
	}

	void Shader::Bind() const
	{
		glUseProgram(m_RendererID);
	}

	void Shader::Unbind() const
	{
		glUseProgram(0);
	}

	void Shader::SetUniform1i(const std::string& name, int value)
	{
		glUniform1i(GetUniformLocation(name), value);
	}

	void Shader::SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
	{
		glUniform4f(GetUniformLocation(name), v0, v1, v2, v3);
	}

	void Shader::SetUniformMat4f(const std::string& name, glm::mat4& mat)
	{
		glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &mat[0][0]);
	}

	int Shader::GetUniformLocation(const std::string& name)
	{
		if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
			return m_UniformLocationCache[name];

		int location = glGetUniformLocation(m_RendererID, name.c_str());
		if (location == -1)
		{
			std::string message = "Warning: Uniform " + name + " does not exist!";
			VZ_CORE_WARN(message);
		}

		m_UniformLocationCache[name] = location;
		return location;
	}
}