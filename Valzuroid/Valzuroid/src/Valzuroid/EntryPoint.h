#pragma once

#ifdef VZ_PLATFORM_WINDOWS

extern Valzuroid::Application* Valzuroid::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Valzuroid::CreateApplication();
	app->Run();
	delete app;
}

#endif