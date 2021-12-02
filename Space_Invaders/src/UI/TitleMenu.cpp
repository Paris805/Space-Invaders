#include "TitleMenu.h"

TitleMenu::TitleMenu()
{
	iCurrentText = 1;
	//loads game font
	LoadGameFont();
	// set the font to all of the texts
	SetTextToFonts();

	// set up the title screen which a character size of 300 that says space invaders
	SetUpTitleText("  Space\n\nInvaders", 300);

	// set the ouline and fill colours for the title screen title text
	ScreenTitle.setFillColor(sf::Color::Black);
	ScreenTitle.setOutlineColor(sf::Color::Yellow);

	// set up the middle button to say play
	SetUpMiddleButtonText("Play");
	//adjust the middle button position
	MiddleButtonText.setPosition(475, MiddleButtonText.getPosition().y);
	// set up the quit button text
	SetUpQuitText();
	
};