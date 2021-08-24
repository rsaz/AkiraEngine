#pragma once
#include <string>

namespace Time
{
	/* Get current time in string format */
	std::wstring ENGINE_API GetTime(BOOL stripped = FALSE);

	/* Get current date in string format */
	std::wstring ENGINE_API GetDate(BOOL stripped = FALSE);

	/* Get current date and tme in strng format */
	std::wstring ENGINE_API GetDateTimeString(BOOL stripped = FALSE);
}