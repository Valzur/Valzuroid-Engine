#pragma once

#include "Event.h"

namespace Valzuroid
{
	class VZ_API ApplicationEvent : public Event
	{
	public:
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class VZ_API WindowCloseEvent : public ApplicationEvent
	{
		public:
			EVENT_CLASS_TYPE(WindowClose)
	};

	class VZ_API WindowResizeEvent : public ApplicationEvent
	{
	public:
		inline WindowResizeEvent(unsigned int width, unsigned int height) 
			: m_Width(width), m_Height(height), ApplicationEvent()
		{

		}
		
		inline unsigned int GetWidth() { return m_Width; }
		inline unsigned int GetHeight() { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Window New Size! X:" << m_Width << " | Y:" << m_Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
	private:
		unsigned int m_Width;
		unsigned int m_Height;
	};
}