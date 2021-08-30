#include "Engine.h"
#include "IApplication.h"
#include "Common/CmdLineArgs.h"

extern Win32::IApplication* EntryApplication();

int CALLBACK WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ INT)
{
	auto entryApplication = EntryApplication();

	auto gameSettings = GameSettings::Instance();
	entryApplication->LoadGameSettings();

	CmdLineArgs::ReadArguments();

	auto logger = Logger::Instance();

	entryApplication->Awake();

	entryApplication->Start();

	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			entryApplication->Update();
		}
	}

	return 0;
}
