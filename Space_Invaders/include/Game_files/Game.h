#ifndef GAME_H
#define GAME_H
#include <SFML\Graphics.hpp>
#include <iostream>
#include <Player.h>
#include <Enemy.h>
#include <Blockades.h>
#include <UI.h>
#include <GameState.h>
#include <vector>

class Game
{
public:

	Game();

	void GameLoop(); // holds the main game loop

	void CheckEvents();// hodls the poll events portion of the prgram

	void UpdateDisplay();// updated the current display

	void DrawScreens();// draws the different screens that can be viewed int the game

	void DrawGameObjects(); // draws all the game objects to the screen (player, enemies ,lasers , blockades)

	void ResetGame();// resets the game so the player can play again

	void MoveObjects();//move all movable objects in the game

	void UpdatePlayerLife();// update the players life

	void PlayerFireCheck();// check if the players laser has hit an enemy

	void EnemyFireCheck();// check if the enemies laser has hit the player or a blockade

	void ConfirmWin();//confirm that all enemies are dead and the player has won

	void CheckForPlayerDeath();// checks if the player has died

	void CheckEnemyPos();// checks if the enemy has reached the bottom of the screen



	sf::RenderWindow* Game_window; // a pointer to a game window object
	GameState CurrentGameState;// effects the game state
	UI UiElements;// holds all the ui elements of the game
	Player* ThePlayer;// pointer to a player object
	Enemy* Enemy0;//pointer to an enemy object
	Blockades* Blocade0;// pointer to a blockade object
	sf::Clock PlayerIdleAnimation;//this clock controlls the player idle animation
	sf::Clock EnemyMovementClock;//this clock controlss the enemies movement speed
	sf::Clock EnemyShootTimes;//this clock controlss the enemies movement speed
	sf::Event checkEvent;// this check the events that occur
};
#endif
