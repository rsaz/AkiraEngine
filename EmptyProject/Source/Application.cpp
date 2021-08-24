#include "pch.h"
#include "Application.h"
#include "Platform/WIN32/WinEntry.h"

ENTRYAPP(Application)

Application::Application() {}
Application::~Application() {}

void Application::LoadGameSettings()
{
	GameSettings::SetGameName(IDS_PERGAMENAME);
	GameSettings::SetShortName(IDS_SHORTNAME);
	GameSettings::SetMainIcon(IDI_MAINICON);
}

void Application::Start()
{
	Logger::PrintDebugSeparator();
	Logger::Print(L"Application Initializing...\n");
	Logger::Print(L"Game Name: %s\n", GameSettings::GameName());
	Logger::Print(L"Game Start Time: %s\n", Time::GetDateTimeString().c_str());
	Logger::PrintDebugSeparator();
	
	Logger::StartMtail();
}
void Application::Update()
{
	//Logger::Print(L"Update Callback every frame");
}