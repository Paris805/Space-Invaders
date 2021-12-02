#ifndef PLAYER_H
#define PLAYER_H

#include <SFML\Graphics.hpp>
#include<iostream>
#include "Character.h"
#include<Laser.h>
#include <PlayerLifeState.h>\


class Player:
	public Character
{
private:
	
	const int kiXShape = 50;// the x value of the player rectangle shape
	const int kiMaxLifeAmmount = 3; // stores the maximum life ammount of the player
	static const int s_kiIdleFrameSize = 8;//number of animation frames
	//static const int DeathFrameSize = 4;//
	
	int iSpeed = 6;//controls the speed of the ship	
	int iYshape = kiXShape; //the y value of the player rectangle
	int iCurrentLife;//stores the current life for the player
	int iIdleCUrrentFrame;// stores the index of the current animation frame
	int iEnemiesKilled;// stores the ammoun of enemies killed

	sf::Vector2f LaseHiddenPosition; //stores the lasers hidden position
	sf::Vector2f DefaultPlayerPosition;// stores the default player postion
	sf::Time AnimationTimeFrame;//stores the elapesd time
	sf::Clock AnimateCLock;// clock for the Idle animation
	sf::IntRect IdleFrames[s_kiIdleFrameSize];//stores the idle animation frames
//	sf::Vector2f playerShipScale;//stores the player ship scale

	Laser PlayerLaser;// stores a laser

public:
	
	bool bCanShoot = 0;
	int iScore;// stores the player score

	
	Player(sf::Vector2u);

	void DrawObjectAttributes(sf::RenderWindow &window);// draws all player aspects to the game window
	void Movement(sf::Event event);//controlls the movement of the player
	
	void InstantiateLaser(sf::Event event);// sets the laser position to the player
	void LaserTravel();// moves the lase across the screen
	void PlayerCanShoot();//determines if the player can shoot
	void Animate(sf::Clock& Time);// controlls the player idle animation
	void ResetObject();// reset the player object
	void UpdateScore(int currentEnemyID, int EnemyQuantity);//update the score

    bool bIsdead;//tells us if the player is dead or not

	sf::Sprite GetSprite();// gets the player sprite

	sf::RectangleShape GetLaser();//gets the player laser

	PlayerLifeState UpdateLifeState;//controlls the players life state
};
#endif