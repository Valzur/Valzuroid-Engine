#include "vzpch.h"
#include "ImGuiLayer.h"

#include "Platform/OpenGL/ImGuiOpenGLRenderer.h"
#include <GLFW/glfw3.h>

#include "Valzuroid/Application.h"

namespace Valzuroid
{
	ImGuiLayer::ImGuiLayer()
		: Layer("ImGui Layer") {}
	ImGuiLayer::~ImGuiLayer() {}

	void ImGuiLayer::OnActivate()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGuiLayer::OnUpdate() 
	{
		ImGuiIO& io = ImGui::GetIO();
		Application& application = Application::Get();
		io.DisplaySize = ImVec2(application.GetWindow().GetWidth(), application.GetWindow().GetHeight());

		float time = (float)glfwGetTime();
		io.DeltaTime = m_Time > 0.0 ? (time - m_Time) : (1.0f / 60.0f);
		m_Time = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImGuiLayer::OnDeactivate() {}

	void ImGuiLayer::OnEvent(Event& e) {}
}