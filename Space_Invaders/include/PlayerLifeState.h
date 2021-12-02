#ifndef PLAYERLIFESTATE_H
#define PLAYERLIFESTATE_H

#include <SFML\Graphics.hpp>
#include <iostream>
#include <Ui.h>

class PlayerLifeState
{
private:
	const int MaxLifeAmmount = 3;// stores the maximum life amount
	int iCurrentLife;// stores the current life
	int iDeathLength;// stores the death length time
	
	
public:
	PlayerLifeState();
	
	void ReduceLife();// reduces the players current life
	void TemporaryDeath(bool& isDead);// excexutes temprorary death sequence where the player is unable to fucntiont for a few seconds
	void Die(bool& isDead);// checks if the player is dead
	void CheckForGameOver();// checks if the game is over
	void ResetPlayerLife();//resets the players current life ammount

	sf::Clock DeathClock;// counts how long the player has been deard for
};
#endif
