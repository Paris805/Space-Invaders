#include "GameOverUI.h"

GameOverUI::GameOverUI()
{
	iCurrentText = 1;
	LoadGameFont();
	SetTextToFonts();

	SetUpTitleText("Game over",250);
	//Playbutton set up
	SetUpMiddleButtonText();

	//quit button set up
	SetUpQuitText();

	//menu button set up
	SetUpLeftButtonText();

	/*StoreArray();*/
	
};

