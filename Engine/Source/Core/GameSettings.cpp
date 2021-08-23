#include "Engine.h"
#include "GameSettings.h"

GameSettings* GameSettings::instance{ nullptr };
std::mutex GameSettings::mutex_;

GameSettings::GameSettings()
	:gameName(L""), shortName(L""), mainIcon(nullptr), startTime(L"")
{
	wcscpy_s(instance->gameName, L"undefined");
	wcscpy_s(instance->shortName, L"undefined");
	wcscpy_s(instance->startTime, L"undefined");
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
