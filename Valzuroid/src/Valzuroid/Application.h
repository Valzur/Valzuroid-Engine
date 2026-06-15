#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"
#include "Layer.h"
#include "Valzuroid/Rendering/Renderer.h"

#include "Valzuroid/Layers/OpenGLFuckery.h"
#include "Valzuroid/ImGui/ImGuiLayer.h"

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
		inline Renderer& GetRenderer() { return *m_Renderer; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Renderer> m_Renderer;
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		OpenGLFuckery* m_OpenGLFuckery;
		bool m_Running = true;

		std::vector<Layer*> m_Layers;

	private:
		static Application* s_Instance;
	};

	// To be defined by the client
	Application* CreateApplication();
}
