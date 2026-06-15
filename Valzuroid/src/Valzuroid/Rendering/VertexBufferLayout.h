#pragma once
#include <vzpch.h>

namespace Valzuroid
{
	struct VZ_API VertexBufferElement
	{
		unsigned int type;
		unsigned int count;
		unsigned char normalized;

		static unsigned int GetSizeOfType(unsigned int type);
	};

	class VZ_API VertexBufferLayout
	{
	private:
		std::vector<VertexBufferElement> m_Elements;
		unsigned int m_Stride;
	public:
		VertexBufferLayout()
			: m_Stride(){}

		template<typename T>
		inline void Push(unsigned int count)
		{
			VZ_ASSERT(false, "Unimplemented!");
		}

		template<>
		void Push<float>(unsigned int count);
		
		template<>
		void Push<unsigned int>(unsigned int count);

		template<>
		void Push<unsigned char>(unsigned int count);

		inline const std::vector<VertexBufferElement>& GetElements() const { return m_Elements; }
		inline unsigned int GetStride() const { return m_Stride; }
	};
}

