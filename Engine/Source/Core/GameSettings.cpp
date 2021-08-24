#include "Engine.h"
#include "GameSettings.h"

GameSettings* GameSettings::instance{ nullptr };
std::mutex GameSettings::mutex_;

GameSettings::GameSettings()
	:gameName(L""), shortName(L""), mainIcon(nullptr), 
	startTime(L"")
{
	instance = this;
	wcscpy_s(instance->startTime, Time::GetDateTimeString(TRUE).c_str());
}

GameSettings::~GameSettings()
{
}

GameSettings* GameSettings::Instance()
{
	std::lock_guard<std::mutex> lock(mutex_);
	if (instance == nullptr)
	{
		instance = new GameSettings;
	}

	return instance;
}
