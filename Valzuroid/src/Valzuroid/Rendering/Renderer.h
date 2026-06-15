#pragma once
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

namespace Valzuroid
{
	class VZ_API Renderer 
	{
	private:

	public:
		void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
		void Clear() const;
	};
}

