#include "Engine.h"
#include "Window.h"

namespace Win32
{
	Window::Window(std::wstring className, std::wstring classTitle, HICON icon, INT width, INT height)
		: WindowBase(className, classTitle, icon), width(width), height(height)
	{
	}

	Window::~Window()
	{
	}

	void Window::Initialize()
	{
		RECT desktop;
		const HWND hDesktop = GetDesktopWindow();
		GetWindowRect(hDesktop, &desktop);

		RECT R = { 0, 0, width, height };
		AdjustWindowRect(&R, WS_OVERLAPPEDWINDOW, false);
		int width = R.right - R.left;
		int height = R.bottom - R.top;

		handle = CreateWindow(className.c_str(), title.c_str(),
			WS_POPUP, ((desktop.right / 2) - (width / 2)), ((desktop.bottom / 2) - (height / 2)), width, height, 0, 0, HInstance(), (void*)this);

		ShowWindow(handle, SW_SHOW);
		UpdateWindow(handle);

	}
}
