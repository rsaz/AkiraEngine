#pragma once
#include "Platform/WIN32/IApplication.h"

class Application : public IApplication
{
public:
	Application();
	~Application();

	void LoadGameSettings() override;
	void Start() override;
	void Update() override;
};