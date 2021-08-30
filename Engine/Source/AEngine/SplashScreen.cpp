#include "Engine.h"
#include "SplashScreen.h"

#include "Platform/Win32/Win32Utils.h"

namespace SplashScreen
{
	#define WM_OUTPUTMESSAGE(WM_USER + 0x0001);

	SplashWindow* splashWindow;

	void Open()
	{
		if (splashWindow != nullptr)
		{
			return;
		}
		splashWindow = new SplashWindow;
	}

	void Close()
	{
		return void ENGINE_API();
	}

	void AddMessage(const WCHAR* message)
	{
		// Fix 1:15
		//PostMessage(splashWindow->GetHandle(), WM_OUTPUTMESSAGE, (WPARAM)message, 0);
	}
}

SplashWindow::SplashWindow()
	: Win32::Window(L"SplashScreen", L"SplashScreen", nullptr, 500, 600)
{
}

SplashWindow::~SplashWindow()
{
}

LRESULT SplashWindow::MessageHandler(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_PAINT:
	{
		HBITMAP hbitmap;
		HDC hdc, hmemdc;
		PAINTSTRUCT ps;

		hdc = BeginPaint(hwnd, &ps);

		Win32::Utils::AddBitmap(GameSettings::SplashURL(), hdc);

		SetBkMode(hdc, TRANSPARENT);
		SetTextColor(hdc, RGB(255, 255, 255));

		if (Engine::GetMode() != Engine::EngineMode::RELEASE) {

			std::wstring engineModeText = Engine::EngineModeToString() + L" Mode";
			SetTextAlign(hdc, TA_RIGHT);
			TextOut(hdc, width - 15, 15, engineModeText.c_str(), wcslen(engineModeText.c_str()));
		}

		SetTextAlign(hdc, TA_CENTER);

		TextOut(hdc, width / 2, height - 30, outputMessage, wcslen(outputMessage));
		EndPaint(hwnd, &ps);
	}
	break;
	case WM_OUTPUTMESSAGE:
	{
		WCHAR* msg = (WCHAR*)wParam;
		wcscpy_s(m_outputMessage, msg);
		RedrawWindow(GetHandle(), NULL, NULL, RDW_INVALIDATE);
		return 0;
	}
	}

	return CommonMessageHandler(hwnd, message, wParam, lParam);
}
