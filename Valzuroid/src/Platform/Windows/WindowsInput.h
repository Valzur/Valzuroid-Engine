#pragma once

#include "Valzuroid/Input.h"

namespace Valzuroid
{
	class WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(int keyCode) override;

		virtual bool IsMouseButtonPressedImpl(int button) override;
		virtual std::pair<double, double> GetMousePositionImpl() override;
		virtual double GetMouseXImpl() override;
		virtual double GetMouseYImpl() override;
	};
}

