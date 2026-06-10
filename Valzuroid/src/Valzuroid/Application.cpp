#include "vzpch.h"
#include "Application.h"
#include <Glad/glad.h>

namespace Valzuroid
{
#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application()
	{
		for (Layer* layer : m_Layers)
			delete layer;
	}

	void Application::Run() 
	{
		while (m_Running) 
		{
			glClearColor(0, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			for (Layer* layer : m_Layers)
				layer->OnUpdate();

			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
		VZ_CORE_INFO("{0}", e.ToString());
		for (auto pos = m_Layers.end(); pos != m_Layers.begin();)
		{
			(*--pos)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_Layers.emplace(m_Layers.begin(), layer);
	}

	void Application::PushLayerToBack(Layer* layer)
	{
		m_Layers.emplace_back(layer);
	}

	void Application::PopLayer(Layer* layer)
	{
		auto pos = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (pos != m_Layers.end())
			m_Layers.erase(pos);
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}