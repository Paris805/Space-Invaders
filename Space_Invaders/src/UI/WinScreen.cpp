#include "WinScreen.h"


WinScreen::WinScreen() 
{
	iCurrentText = 1;
	//loads game font
	LoadGameFont();
	// sets the fonts to the differnt texts
	SetTextToFonts();

	//win text set up
	SetUpTitleText("WINNER ", 325);
	
	//Playbutton set up
	SetUpMiddleButtonText();

	//quit button set up
	SetUpQuitText();

	//menu button set up
	SetUpLeftButtonText();
	
}
