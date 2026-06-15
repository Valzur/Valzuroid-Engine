#pragma once

namespace Valzuroid
{
	class VZ_API IndexBuffer
	{
	private:
		unsigned int m_RendererID;
		unsigned int m_Count;
	public:
		IndexBuffer(const unsigned int* data, unsigned int count);
		~IndexBuffer();

		inline unsigned int GetCount() const { return m_Count; }

		void Bind() const;
		void Unbind() const;
	};
}