#pragma once
#include "Valzuroid/Layer.h"

namespace Valzuroid
{
	class OpenGLFuckery : public Layer
	{
		virtual void OnEvent(Event& e) override;

		virtual void OnActivate() override;
	};
}