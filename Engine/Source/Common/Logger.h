#pragma once
#include <mutex>
#include <string>

class ENGINE_API Logger
{
private:
	static Logger* instance;
	static std::mutex mutex_;
protected:
	Logger();
	~Logger();
public:
	Logger(Logger& other) = delete;
	void operator=(const Logger&) = delete;

	static Logger* Instance();

	static void Print(const WCHAR* fmt, ...);
	static std::wstring LogDirectory();
	static std::wstring LogFile();

	/* Priting trail and Mtail implementation for log */
	static void PrintDebugSeparator();

	static bool IsMTailRunning();

	static void StartMtail();
};