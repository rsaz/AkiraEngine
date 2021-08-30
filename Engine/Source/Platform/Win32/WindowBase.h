#pragma once

namespace Win32
{
	class ENGINE_API WindowBase
	{
	protected:
		std::wstring	className;
		std::wstring	title;
		HICON			hIcon;
		HWND			handle;

		static			LRESULT CALLBACK	SetupMessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
		static			LRESULT				AssignMessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
		virtual			LRESULT				CommonMessageHandler(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
		virtual			LRESULT				MessageHandler(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) = 0;

	public:
		WindowBase(std::wstring className, std::wstring classTitle, HICON icon);
		~WindowBase();

		virtual void RegisterNewClass();
		virtual void Initialize() = 0;

		HWND GetHandle() { return handle; }
	};
}
