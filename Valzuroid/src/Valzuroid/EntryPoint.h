#pragma once

#ifdef VZ_PLATFORM_WINDOWS

extern Valzuroid::Application* Valzuroid::CreateApplication();

int main(int argc, char** argv)
{
	Valzuroid::Log::Init();
	VZ_CORE_WARN("Log Init");
	VZ_INFO("Log Init");

	auto app = Valzuroid::CreateApplication();
	app->Run();
	delete app;
}

#endif