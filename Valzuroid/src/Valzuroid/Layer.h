#pragma once
#include "vzpch.h"
#include "Core.h"
#include "Events/Event.h"

namespace Valzuroid
{
	class VZ_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnActivate();
		virtual void OnUpdate() = 0;
		virtual void OnDeactivate();

		virtual void OnEvent(Event& e) = 0;

		inline const std::string & GetName() const { return m_Name; }
	protected:
		std::string m_Name;
	};
}