#pragma once

#define ENTRYAPP(obj) Win32::IApplication* EntryApplication() { return new obj;}

namespace Win32
{
	class ENGINE_API IApplication
	{
	public:
		IApplication();
		virtual ~IApplication() {};

		/* Load initial game settings */
		virtual void LoadGameSettings() = 0;

		/* Called before start */
		virtual void Awake() = 0;

		/* Called once at start */
		virtual void Start() = 0;

		/* Called every frame */
		virtual void Update() = 0;
	};

	IApplication* EntryApplication();
}