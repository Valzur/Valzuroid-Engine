#pragma once

#include "Core.h"

namespace Valzuroid
{
	class VALZUROID_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined by the client
	Application* CreateApplication();
}
