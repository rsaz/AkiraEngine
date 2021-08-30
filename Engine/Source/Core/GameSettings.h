#pragma once
#include <mutex>

class ENGINE_API GameSettings
{
private:
	static GameSettings* instance;
	static std::mutex mutex_;

	WCHAR gameName[MAX_NAME_STRING];
	WCHAR shortName[MAX_NAME_STRING];
	HICON mainIcon;
	WCHAR startTime[MAX_NAME_STRING];
	WCHAR splashURL[MAX_NAME_STRING];
protected:
	GameSettings();
	~GameSettings();
public:
	GameSettings(GameSettings& other) = delete;
	void operator=(const GameSettings&) = delete;

	static GameSettings* Instance();

	// Implement Getters and Setters 35::55
	static WCHAR* GameName() { return instance->gameName; }
	static void SetGameName(UINT id) { LoadString(HInstance(), id, instance->gameName, MAX_NAME_STRING); }

	static WCHAR* ShortName() { return instance->gameName; }
	static void SetShortName(UINT id) { LoadString(HInstance(), id, instance->shortName, MAX_NAME_STRING); }

	static HICON MainIcon() { return instance->mainIcon; }
	static void SetMainIcon(UINT id) { LoadIcon(HInstance(), MAKEINTRESOURCE(id)); }

	static WCHAR* StartTime() { return instance->startTime; }

	static WCHAR* SplashURL() { return instance->splashURL; }
	static VOID SetSplashURL(UINT id) { LoadString(HInstance(), id, instance->splashURL, MAX_NAME_STRING); }
};