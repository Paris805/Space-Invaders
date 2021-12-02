#include "PauseScreen.h"

PauseScreen::PauseScreen() 
{
	LoadGameFont();
	SetTextToFonts();
	SetUpMiddleButtonText("Press any key to start");
	MiddleButtonText.setPosition(300, MiddleButtonText.getPosition().y);
}
void PauseScreen::ResumeGame() 
{
	GameState::PauseGame();
}