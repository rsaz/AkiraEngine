#include "Engine.h"

namespace Engine
{
	AEngine globalAEngine;

	void SetMode(EngineMode mode)
	{
		globalAEngine.SetEngineMode(mode);
	}

	EngineMode GetMode()
	{
		return globalAEngine.GetEngineMode();
	}

	std::wstring ENGINE_API EngineModeToString()
	{
		switch (Engine::GetMode())
		{
		case EngineMode::DEBUG:		return L"Debug";
		case EngineMode::RELEASE:	return L"Release";
		case EngineMode::SERVER:	return L"Server";
		case EngineMode::EDITOR:	return L"Editor";
		default:     return L"None";
		}
	}
}

AEngine::AEngine()
{
#ifdef _DEBUG
	engineMode = EngineMode::DEBUG;
#else
	engineMode = EngineMode::RELEASE;
#endif // _DEBUG
}

AEngine::~AEngine()
{
}

EngineMode AEngine::GetEngineMode() { return engineMode; }
void AEngine::SetEngineMode(EngineMode mode) { engineMode = mode; }

