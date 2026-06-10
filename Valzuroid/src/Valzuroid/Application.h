#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"
#include "Layer.h"

namespace Valzuroid
{
	class VZ_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
		 
		void PushLayer(Layer* layer);
		void PushLayerToBack(Layer* layer);
		void PopLayer(Layer* layer);

		static inline Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		std::vector<Layer*> m_Layers;

	private:
		static Application* s_Instance;
	};

	// To be defined by the client
	Application* CreateApplication();
}
