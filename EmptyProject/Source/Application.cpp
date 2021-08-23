#include "pch.h"
#include "Application.h"
#include "Platform/WIN32/WinEntry.h"

ENTRYAPP(Application)

Application::Application() {}
Application::~Application() {}

void Application::Start()
{
	MessageBox(0, L"Start Callback", 0, 0);
}
void Application::Update()
{
	MessageBox(0, L"Update Callback", 0, 0);
}