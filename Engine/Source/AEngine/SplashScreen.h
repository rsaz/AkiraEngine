#pragma once
#include "Platform/Win32/Window.h"

namespace SplashScreen
{
	void ENGINE_API Open();
	void ENGINE_API Close();
	void ENGINE_API AddMessage(const WCHAR* message);
}

class ENGINE_API SplashWindow : public Win32::Window
{
private:
	WCHAR outputMessage[MAX_NAME_STRING];
public:
	SplashWindow();
	~SplashWindow();

	virtual LRESULT MessageHandler(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) override;
};