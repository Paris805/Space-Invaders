#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <SFML\Graphics.hpp>
#include <iostream>

//this class is responsible for adjusting the current game state, to switch between menus and win and loose states
class GameState
{
private:
	static bool s_bGameOn; 
	static bool s_bWinState;
    static bool s_bGameOver;
	static bool s_bGamePaused;
	
public:

    static bool s_bInMainMenu;
	bool& bGameOnRef = s_bGameOn;
	bool& bhasWon = s_bWinState;
	bool& bhasLost = s_bGameOver;
	bool& bGameIsPaused = s_bGamePaused;
	GameState();

	static void StartGame();
	static void EndGame();
	static void WonGame();
	static void PauseGame();
	static void EnableMenu();

};

#endif