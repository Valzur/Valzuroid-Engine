#include "vzpch.h"
#include "Renderer.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Valzuroid
{
	void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const
	{
		shader.Bind();

		glClear(GL_COLOR_BUFFER_BIT);

		va.Bind();
		ib.Bind();

		glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr);
	}

	void Renderer::Clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}
}