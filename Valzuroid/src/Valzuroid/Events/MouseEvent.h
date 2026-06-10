#pragma once

#include "Event.h"

namespace Valzuroid
{
	class VZ_API MouseButtonEvent : public Event
	{
	public: 
		MouseButtonEvent(int button):
			m_Button(button){}

		EVENT_CLASS_CATEGORY(EventCategoryMouseButton)
	protected:
		int m_Button;
	};

	class VZ_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button) :
			MouseButtonEvent(button){}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class VZ_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button) :
			MouseButtonEvent(button) {}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

	class VZ_API MouseScrollEvent : public Event
	{
	public:
		MouseScrollEvent(double xOffset, double yOffset) : 
			m_XOffset(xOffset), m_YOffset(yOffset){}

		inline double GetXOffset() { return m_XOffset; }
		inline double GetYOffset() { return m_YOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Scrolled! X: " << m_XOffset << "| Y:" << m_YOffset << std::endl;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryMouse)
		EVENT_CLASS_TYPE(MouseScrolled)
	private:
		double m_XOffset;
		double m_YOffset;
	};
	
	class VZ_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(double xPos, double yPos) :
			m_XPos(xPos), m_YPos(yPos){}

		inline double GetXPos() { return m_XPos; }
		inline double GetYPos() { return m_YPos; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Moved! X: " << m_XPos << "| Y:" << m_YPos << std::endl;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryMouse)
		EVENT_CLASS_TYPE(MouseMoved)
	private:
		double m_XPos;
		double m_YPos;
	};
}