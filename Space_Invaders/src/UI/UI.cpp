#include <UI.h>



UI::UI()
{
	
};


void UI::DrawAllUiElements(sf::RenderWindow &gameWindow)
{
	gameWindow.draw(Hearts.HeartUIShape);// draw the Life ui to the game window
};

void UI::DrawGameOverScreen(sf::RenderWindow& gameWindow) 
{
  gameWindow.draw(GameOverText.ScreenTitle); 
  gameWindow.draw(GameOverText.MiddleButtonText);
  gameWindow.draw(GameOverText.RightButtonText);
  gameWindow.draw(GameOverText.LeftButtonText);
};
void UI::DrawInGameScreen(sf::RenderWindow& gameWindow)
{
	gameWindow.draw(Hearts.HeartUIShape);// draw the Life ui to the game window
	gameWindow.draw(ScoreUi.MiddleButtonText);
};

void UI::DrawWinScreen(sf::RenderWindow& gameWindow) 
{
	gameWindow.draw(WinScreenUI.ScreenTitle);
	gameWindow.draw(WinScreenUI.MiddleButtonText);
	gameWindow.draw(WinScreenUI.RightButtonText);
	gameWindow.draw(WinScreenUI.LeftButtonText);
};

void UI::DrawPauseScreen(sf::RenderWindow& gameWindow)
{	
	gameWindow.draw(PausedUI.MiddleButtonText);	
};
void UI::DrawTitleMenu(sf::RenderWindow& gameWindow)
{
	gameWindow.draw(TitleScreen.ScreenTitle);
	gameWindow.draw(TitleScreen.MiddleButtonText);
	gameWindow.draw(TitleScreen.RightButtonText);
	gameWindow.draw(TitleScreen.LeftButtonText);
};


