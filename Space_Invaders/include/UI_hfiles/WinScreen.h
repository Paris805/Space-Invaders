#ifndef WINSCREEN_H
#define WINSCREEN_H
#include <UiScreens.h>

class WinScreen :
	public UiScreens
{
public:
	WinScreen();
	
	sf::Text WinText;
};

#endif