#include "pch.h"

#pragma region Global Variables
WCHAR	windowClass[MAX_NAME_STRING];
WCHAR	windowTitle[MAX_NAME_STRING];
INT		windowWidth;
INT		windowHeight;
HICON	hIcon;
#pragma endregion

#pragma region Prototype Functions
void InitializeVaribales();
void CreateRegisterWindowClass();
void DisplayWindow();
void MessageLoop();
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
#pragma endregion

#pragma region Operations
int CALLBACK WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ INT)
{
	InitializeVaribales();

	CreateRegisterWindowClass();
	
	DisplayWindow();

	MessageLoop();

	return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

#pragma endregion

#pragma region Function Implementation
void InitializeVaribales()
{
	LoadString(HInstance(), IDS_WINDOWCLASS, windowClass, MAX_NAME_STRING);
	LoadString(HInstance(), IDS_PERGAMENAME, windowTitle, MAX_NAME_STRING);
	windowWidth = 1366;
	windowHeight = 768;
	hIcon = LoadIcon(HInstance(), MAKEINTRESOURCE(IDI_MAINICON));
}

void CreateRegisterWindowClass()
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);

	wcex.hIcon = hIcon;
	wcex.hIconSm = hIcon;

	wcex.lpszClassName = windowClass;
	wcex.lpszMenuName = nullptr;
	wcex.hInstance = HInstance();
	wcex.lpfnWndProc = WindowProc;

	RegisterClassEx(&wcex);
}

void DisplayWindow()
{
	HWND hWnd = CreateWindow(windowClass, windowTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0,
		windowWidth, windowHeight, nullptr, nullptr, HInstance(), nullptr);

	if (!hWnd)
	{
		MessageBox(0, L"Failed to created window!", 0, 0);
		PostQuitMessage(0);
	}
	else
	{
		ShowWindow(hWnd, SW_SHOW);
	}
}

void MessageLoop()
{
	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}
#pragma endregion