#ifndef UI_H
#define UI_H

#include <SFML\Graphics.hpp>
#include <PlayerLifeUi.h>
#include<GameOverUI.h>
#include <WinScreen.h>
#include <PauseScreen.h>
#include <TitleMenu.h>
#include <ScoreUI.h>

class UI
{
private:
	
	
    
public:

	UI();
	void DrawAllUiElements(sf::RenderWindow& gameWindow);
	void DrawGameOverScreen(sf::RenderWindow& gameWindow);
	void DrawInGameScreen(sf::RenderWindow& gameWindow);
	void DrawWinScreen(sf::RenderWindow& gameWindow);
	void DrawPauseScreen(sf::RenderWindow& gameWindow);
	void DrawTitleMenu(sf::RenderWindow& gameWindow);

	PlayerLifeUi Hearts;
	GameOverUI GameOverText;
	WinScreen WinScreenUI;
	PauseScreen PausedUI;
	TitleMenu TitleScreen;
	ScoreUI ScoreUi;
};

#endif