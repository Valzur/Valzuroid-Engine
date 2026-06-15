#include "vzpch.h"
#include "Layer.h"

namespace Valzuroid
{
	Layer::Layer(const std::string& name)
	: m_Name(name){}
	Layer::~Layer()
	{

	}
	void Layer::OnActivate(){}
	void Layer::OnUpdate(){}
	void Layer::OnImGuiRender() {}
	void Layer::OnDeactivate(){}
}