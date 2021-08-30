#pragma once
#include "WindowBase.h"

namespace Win32
{
	class ENGINE_API Window : public WindowBase
	{
	protected:
		int width;
		int height;
	public:
		Window(std::wstring className, std::wstring classTitle, HICON icon, INT width, INT height);
		~Window();

		virtual void Initialize() override;
	};
}