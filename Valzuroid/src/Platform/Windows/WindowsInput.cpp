#include "vzpch.h"
#include "WindowsInput.h"

#include "Valzuroid/Application.h"
#include <GLFW/glfw3.h>

namespace Valzuroid
{
	Input* Input::s_Instance = new WindowsInput();

	bool WindowsInput::IsKeyPressedImpl(int keyCode)
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		int state = glfwGetKey(window, keyCode);

		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WindowsInput::IsMouseButtonPressedImpl(int button) 
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		int state = glfwGetMouseButton(window, button);

		return state == GLFW_PRESS;
	}

	std::pair<double, double> WindowsInput::GetMousePositionImpl()
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double xPos, yPos;
		glfwGetCursorPos(window, &xPos, &yPos);

		return { xPos, yPos };
	}

	double WindowsInput::GetMouseXImpl()
	{
		auto [x, y] = GetMousePositionImpl();

		return x;
	}

	double WindowsInput::GetMouseYImpl()
	{
		auto [x, y] = GetMousePositionImpl();

		return y;
	}

}