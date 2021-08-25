#include "EmptyProject.h"
#include "AEngine/Simulation.h"
#include "Platform/Win32/WinEntry.h"

class EmptyProject : public Engine::Simulation
{
public:
	EmptyProject() {};
	~EmptyProject() {};

	void LoadGameSettings();
	void Start() {};
	void Update() {};
};

ENTRYAPP(EmptyProject)
void EmptyProject::LoadGameSettings()
{
	GameSettings::SetGameName(IDS_PERGAMENAME);
	GameSettings::SetShortName(IDS_SHORTNAME);
	GameSettings::SetMainIcon(IDI_MAINICON);
}