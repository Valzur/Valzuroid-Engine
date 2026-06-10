#pragma once
#include "Valzuroid/Layer.h"

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
		float m_Time = 0.0f;
	};
}

