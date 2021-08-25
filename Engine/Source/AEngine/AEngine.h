#pragma once

class ENGINE_API AEngine;
namespace Engine
{
	enum class EngineMode : INT
	{
		NONE = 0,
		DEBUG,
		RELEASE,
		EDITOR,
		SERVER
	};

	extern AEngine globalAEngine;

	void ENGINE_API SetMode(EngineMode mode);
	EngineMode ENGINE_API GetMode();
	std::wstring ENGINE_API EngineModeToString();
}

using namespace Engine;
class ENGINE_API AEngine
{
private:
	EngineMode engineMode;
public:
	AEngine();
	~AEngine();

	EngineMode GetEngineMode();
	void SetEngineMode(EngineMode mode);
};