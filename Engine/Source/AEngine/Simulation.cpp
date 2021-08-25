#include "Engine.h"
#include "Simulation.h"

Engine::Simulation::Simulation()
{
}

Engine::Simulation::~Simulation()
{
}

void Engine::Simulation::Awake()
{
	Logger::PrintDebugSeparator();
	Logger::Print(L"Application Starting...\n");
	Logger::Print(L"Game Name: %s\n", GameSettings::GameName());
	Logger::Print(L"Boot Time: %s\n", Time::GetDateTimeString().c_str());
	Logger::Print(L"Engine Mode: %s\n", Engine::EngineModeToString().c_str());

	Logger::PrintDebugSeparator();

	//SplashScreen::Open();
}
