#pragma once
#include "Valzuroid/Layer.h"

#include "Valzuroid/Events/KeyEvent.h"
#include "Valzuroid/Events/MouseEvent.h"
#include "Valzuroid/Events/ApplicationEvent.h"

enum ImGuiKey;

namespace Valzuroid
{
	class VZ_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnActivate();
		void OnUpdate();
		void OnDeactivate();

		void OnEvent(Event& e);

	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseScrollEvent(MouseScrollEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnWindowResizeEvent(WindowResizeEvent& e);
		static ImGuiKey KeyToImGuiKey(int keycode);

	private:
		float m_Time = 0.0f;
	};
}

