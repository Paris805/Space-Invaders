#include "GameState.h"


bool GameState::s_bGameOn = false;
bool GameState::s_bWinState = false;
bool GameState::s_bGameOver = false;
bool GameState::s_bGamePaused = false;
bool GameState::s_bInMainMenu = true;


GameState::GameState()
{	
};

void GameState::StartGame()// starts the game up
{
	s_bGameOn = true;
	s_bGameOver = false;
	s_bWinState = false;
};

void GameState::EndGame()// Changes game state to the game over screen
{
	s_bGameOn = false;
	s_bGameOver = true;
};

void GameState::WonGame()//changes game state to the win screen.
{
	s_bWinState = true;
	s_bGameOn = false;


}
 void GameState::PauseGame()
{
	s_bGamePaused = !s_bGamePaused;
	s_bGameOn = true;
	s_bGameOver = false;
	s_bWinState = false;
	s_bInMainMenu = false;
	
}
 void GameState::EnableMenu() 
 {	 
		 s_bInMainMenu = true;
		 s_bGameOn = false;
		 s_bGameOver = false;
		 s_bWinState = false;
		 s_bGamePaused = false;
 };