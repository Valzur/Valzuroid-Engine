#include "vzpch.h"
#include "OpenGLFuckery.h"
#include "Valzuroid/Application.h"
#include "Valzuroid/Rendering/VertexBuffer.h"
#include "Valzuroid/Rendering/IndexBuffer.h"
#include "Valzuroid/Rendering/VertexArray.h"
#include "Valzuroid/Rendering/VertexBufferLayout.h"
#include "Valzuroid/Rendering/Shader.h"
#include "Valzuroid/Rendering/Texture.h"

#include <chrono>
#include <filesystem>
#include <string>
#include <fstream>
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Valzuroid
{
	static void HandleGLErrors(GLenum source,
		GLenum type,
		GLuint id,
		GLenum severity,
		GLsizei length,
		const GLchar* message,
		const void* _)
	{
		std::stringstream ss;
		ss << "OpenGL ERROR! Details:\n" 
			<< "Source: " << source << "\n" 
			<< "Type: " << type << "\n"
			<< "ID: " << id << "\n"
			<< "Severity " << severity << "\n"
			<< "Message: ";
		ss.write(message, length);

		VZ_CORE_ASSERT(type != GL_DEBUG_TYPE_ERROR, ss.str());
		if(type != GL_DEBUG_TYPE_ERROR)
			VZ_CORE_WARN(ss.str());
	}

	void OpenGLFuckery::OnActivate()
	{
		// Only debugging
		glEnable(GL_DEBUG_OUTPUT);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
		glDebugMessageCallback(HandleGLErrors, nullptr);
		glfwWindowHint(GLFW_CONTEXT_DEBUG, GL_TRUE);
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		float positions[] =
		{
			-0.5f,  0.5f, 0.0f, 1.0f,
			-0.5f, -0.5f, 0.0f, 0.0f,
			 0.5f, -0.5f, 1.0f, 0.0f,
			 0.5f,  0.5f, 1.0f, 1.0f,
		};

		unsigned int indices[]
		{
			0, 1, 2,
			2, 3, 0
		};

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		VertexArray va;
		VertexBuffer vb(positions, 16 * sizeof(float));
		IndexBuffer ib(indices, 6);

		VertexBufferLayout layout;
		layout.Push<float>(2);
		layout.Push<float>(2);
		va.AddBuffer(vb, layout);

		//T left, T right, T bottom, T top, T zNear, T zFar
		int width;
		int height;
		float scale = 0.5f;
		glfwGetWindowSize(window, &width, &height);
		float widthToHeight = (float)width / height;
		float imageAspect = 1280.0f / 800.0f;
		glm::mat4 proj = glm::ortho(-widthToHeight / imageAspect * scale, widthToHeight / imageAspect * scale, -scale, scale);

		Shader shader("../Valzuroid/resources/shaders/Basic.shader");
		shader.Bind();
		shader.SetUniformMat4f("u_MVP", proj);
		
		Texture texture("../Valzuroid/resources/textures/vz.png");
		texture.Bind();
		shader.SetUniform1i("u_Texture", 0);

		va.Unbind();
		vb.Unbind();
		ib.Unbind();
		shader.Unbind();

		float r = 0;
		float deltaChange = 1;
		float speed = 0.000'000'001;
		std::chrono::steady_clock clock;
		auto startTime = std::chrono::steady_clock::now();
		Renderer renderer = Application::Get().GetRenderer();
		while (!glfwWindowShouldClose(window))
		{
			if (r == 0)
			{
				deltaChange = 1;
			}
			else if (r == 1)
			{
				deltaChange = -1;
			}
			
			auto timeNow = std::chrono::steady_clock::now();
			auto deltaTime = std::chrono::duration_cast<std::chrono::nanoseconds>(timeNow - startTime);
			startTime = timeNow;

			r += deltaChange * deltaTime.count() * speed;
			r = std::clamp(r, 0.0f, 1.0f);

			renderer.Clear();

			shader.Bind();
			shader.SetUniform4f("u_Color", 0.5f, r, r, 1.0f);

			renderer.Draw(va, ib, shader);

			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}

	void OpenGLFuckery::OnEvent(Event& e){}
}