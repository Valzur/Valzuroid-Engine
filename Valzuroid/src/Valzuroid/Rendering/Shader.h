#pragma once

#include <glm/glm.hpp>

namespace Valzuroid
{
	struct VZ_API ShaderProgramSource
	{
		std::string VertexSource;
		std::string FragmentSource;
	};

	class VZ_API Shader
	{
	private:
		std::string m_FilePath;
		unsigned int m_RendererID;
		std::unordered_map<std::string, int> m_UniformLocationCache;
	public:
		Shader(const std::string& filePath);
		~Shader();

		void Bind() const;
		void Unbind() const;

		// Set uniforms
		void SetUniform1i(const std::string& name, int value);
		void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
		void SetUniformMat4f(const std::string& name, glm::mat4& mat);

		static ShaderProgramSource Parse(const std::string& filePath);
		static unsigned int Create(const std::string& vertexShader, const std::string& fragmentShader);
		static unsigned int Compile(unsigned int type, const std::string& source);

	private:
		int GetUniformLocation(const std::string& name);
	};
}
