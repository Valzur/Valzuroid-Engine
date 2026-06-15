#pragma once

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

namespace Valzuroid
{
	class VZ_API VertexArray
	{
	private:
		unsigned int m_RendererID;
	public:
		VertexArray();
		~VertexArray();
	
		void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
		void Bind() const;
		void Unbind() const;
	};
}

