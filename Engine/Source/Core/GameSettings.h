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
protected:
	GameSettings();
	~GameSettings();
public:
	GameSettings(GameSettings& other) = delete;
	void operator=(const GameSettings&) = delete;

	static GameSettings* Instance();

	// Implement Getters and Setters 35::55

};