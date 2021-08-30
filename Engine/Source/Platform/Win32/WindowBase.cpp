#include "Engine.h"
#include "WindowBase.h"

namespace Win32
{
	WindowBase::WindowBase(std::wstring className, std::wstring classTitle, HICON icon)
		: className(className), title(classTitle), hIcon(icon), handle(0)
	{
	}

	WindowBase::~WindowBase()
	{
	}

	void WindowBase::RegisterNewClass()
	{
		WNDCLASSEX wcex;
		wcex.cbSize = sizeof(WNDCLASSEX);
		wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wcex.hbrBackground = (HBRUSH)(CreateSolidBrush(RGB(46, 46, 46)));
		wcex.hIcon = hIcon;
		wcex.hIconSm = hIcon;
		wcex.lpszClassName = className.c_str();
		wcex.lpszMenuName = nullptr;
		wcex.hInstance = HInstance();
		wcex.lpfnWndProc = SetupMessageHandler;
		RegisterClassEx(&wcex);
	}


	LRESULT WindowBase::SetupMessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		if (msg == WM_NCCREATE)
		{
			const CREATESTRUCTW* const pCreate = reinterpret_cast<CREATESTRUCTW*>(lParam);
			WindowBase* const pWnd = static_cast<WindowBase*>(pCreate->lpCreateParams);
			SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWnd));
			SetWindowLongPtr(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&WindowBase::AssignMessageHandler));
			return pWnd->MessageHandler(hWnd, msg, wParam, lParam);
		}
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	LRESULT WindowBase::AssignMessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		Win32::WindowBase* const pWnd = reinterpret_cast<Win32::WindowBase*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
		return pWnd->MessageHandler(hWnd, msg, wParam, lParam);
	}

	LRESULT WindowBase::CommonMessageHandler(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		return DefWindowProc(hwnd, message, wParam, lParam);
	}

#pragma endregion
}


