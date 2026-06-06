#include <Valzuroid.h>

class Sandbox : public Valzuroid::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Valzuroid::Application* Valzuroid::CreateApplication()
{
	return new Sandbox();
}