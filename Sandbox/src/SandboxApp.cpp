#include <Valzuroid.h>

class TestLayer : public Valzuroid::Layer
{
public:
	TestLayer() 
		: Valzuroid::Layer("Test Layer"){}
	~TestLayer(){}

	void OnUpdate() override
	{
		VZ_INFO("Test Layer::Update");
	}

	void OnEvent(Valzuroid::Event& e) override
	{
		VZ_TRACE("{0}", e.ToString());
	}
};

class Sandbox : public Valzuroid::Application
{
public:
	Sandbox()
	{
		PushLayer(new TestLayer());
	}

	~Sandbox()
	{

	}
};

Valzuroid::Application* Valzuroid::CreateApplication()
{
	return new Sandbox();
}