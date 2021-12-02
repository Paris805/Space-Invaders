#ifndef PAUSESCREEN_H
#define PAUSESCREEN_H
#include <UiScreens.h>

class PauseScreen:
	public UiScreens
{
	
public:
	PauseScreen();
	void ResumeGame();// resumes game when called

};

#endif 