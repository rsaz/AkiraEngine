#include "Engine.h"
#include <fstream>
#include <ShlObj.h>
#include <cstdio>
#include <tlhelp32.h>

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

	if (logFile.is_open())
	{
		std::wstring s = buffer;
		logFile << L"[" << Time::GetDateTimeString() << L"] " << s;
		logFile.close();
		OutputDebugString(s.c_str());
	}
	else
	{
		MessageBox(0, L"Unable to open log file...", L"Log Error", MB_OK);
	}
	
}

std::wstring Logger::LogDirectory()
{
	WCHAR path[1024];
	WCHAR* appDataLocal;
	SHGetKnownFolderPath(FOLDERID_RoamingAppData,0, nullptr, &appDataLocal);
	wcscpy_s(path, appDataLocal);
	wcscat_s(path, L"\\");
	wcscat_s(path, GameSettings::GameName());
	CreateDirectory(path, NULL);
	wcscat_s(path, L"\\Log");
	CreateDirectory(path, NULL);

	return path;
}

std::wstring Logger::LogFile()
{
	WCHAR file[1024];
	wcscpy_s(file, GameSettings::GameName());
	wcscat_s(file, GameSettings::StartTime());
	wcscat_s(file, L".log");

	return file;
}

void Logger::PrintDebugSeparator()
{
	std::wstring s = L"\n------------------------------------------------------------------------------------\n\n";

#ifdef _DEBUG
	std::wfstream outfile;
	outfile.open(std::wstring(LogDirectory() + L"/" + LogFile()), std::ios_base::app);

	if (outfile.is_open()) {
		outfile << s;
		outfile.close();
	}
	else {
		MessageBox(NULL, L"Unable to open log file...", L"Log Error", MB_OK);
	}
#endif
}

bool Logger::IsMTailRunning()
{
	bool exists = false;
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (Process32First(snapshot, &entry))
		while (Process32Next(snapshot, &entry))
			if (!_wcsicmp(entry.szExeFile, L"mTAIL.exe"))
				exists = true;

	CloseHandle(snapshot);
	return exists;
}

void Logger::StartMtail()
{
	if (IsMTailRunning()) {
		Logger::Print(L"--MTail failed to start - Already Running\n");
		return;
	}

	Logger::Print(L"--Starting MTail\n");
	WCHAR path[MAX_PATH] = { 0 };
	GetCurrentDirectoryW(MAX_PATH, path);
	std::wstring url = path + std::wstring(L"/mTAIL.exe");
	std::wstring params = L" \"" + LogDirectory() + L"/" + LogFile() + L"\" /start";
	ShellExecute(0, NULL, url.c_str(), params.c_str(), NULL, SW_SHOWDEFAULT);
}
