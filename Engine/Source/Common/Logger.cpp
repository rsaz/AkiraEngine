#include "Engine.h"
#include <fstream>
#include <ShlObj.h>

Logger* Logger::instance{ nullptr };
std::mutex Logger::mutex_;

Logger::Logger()
{
}

Logger::~Logger()
{
}

Logger* Logger::Instance()
{
	std::lock_guard<std::mutex> lock(mutex_);
	if (instance == nullptr)
	{
		instance = new Logger;
	}
	
	return instance;
}

void Logger::Print(const WCHAR* fmt, ...)
{
	WCHAR buffer[4096];
	va_list args;
	va_start(args, fmt);
	vswprintf_s(buffer, fmt, args);
	va_end(args);

	std::wfstream logFile;
	logFile.open(std::wstring(LogDirectory() + L"/" + LogFile()), std::ios_base::app);
}

std::wstring Logger::LogDirectory()
{
	WCHAR path[1024];
	WCHAR* appDataLocal;
	SHGetKnownFolderPath(FOLDERID_RoamingAppData,0, nullptr, &appDataLocal);
	wcscpy_s(path, appDataLocal);
	wcscpy_s(path, L"\\");
	wcscpy_s(path, L"Game Name");
	CreateDirectory(path, NULL);
	wcscpy_s(path, L"\\Log");
	CreateDirectory(path, NULL);

	return path;
}
