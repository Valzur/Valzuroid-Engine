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

		virtual void OnActivate() override;
		virtual void OnDeactivate() override;

		void OnEvent(Event& e);

		virtual void Start();
		virtual void OnImGuiRender() override;
		virtual void End();
	private:

	private:
		float m_Time = 0.0f;
	};
}

