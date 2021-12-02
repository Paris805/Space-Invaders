#ifndef ENEMY_H
#define ENEMY_H
#include <SFML\Graphics.hpp>
#include <iostream>
#include<vector>
#include<stdlib.h>
#include <time.h>
#include <ctime>
#include <Character.h>
#include "Laser.h"

class Enemy: 
	public Character
{
private:
	//sf::Clock EnemyMovementClock;
	const int kiShapeDimension = 50; //length and width of shape
	const static int ks_iNumberOfEnemies = 11; // stores the number of enemies in a single row
	const int kiNumberOfEnnemyRows = 5;// stores the total number of enemy rows
	
	const float kfSpeedLimit = 0.1f;// stores the speed limit that enemies can travel at
	const float kfSpeedIncrease = 0.1f;// stores the amount the ememy speed can be increasd by at a time

	const sf::Vector2f kvSpaceBetween = sf::Vector2f(40, 60);//stored the x and y distance between each enemy

	static bool s_bBoundaryReached;//stores the result of if an enemy has reached a boundary or not
	static int s_iCurrentDirection;// stores the current direction in which every enemy should travel in

    int iEnemiesKilled; //stores how many enemies have been killed
	int iStartXPos;// stors the starting x position of the first enemy places on screen
	int iRight = 20;// stores the right direction	
	int iStartDelay;//stored the start delay before enemies can shoot
	int icurrentEnemyLaser;//stores the index of the currenet enemy laser
	int iPickTimeDelay();// picks a random time delay between the last shot and the next shot
	int iPickFiringEnemy();// picks a random enemy from an array of enemies that are eligable to fire
	int iTotalEnemies = ks_iNumberOfEnemies *kiNumberOfEnnemyRows;//stores the total number of enemies (55)

	float fCurrentSpeed;// stores the current speed of the enemies
	
	void CheckEnemyShootStaus(int &EnemyVectorID); //checks if an enemy is on screen to beable to shoot the player
	
	sf::Clock EnemyMovementClock;//this clock controlss the enemies movement speed
	sf::Clock EnemyShootTimes;//this clock controlss the enemies movement speed
		
	sf::Time timeSinceLastRestart; //stores the time since the enemy clock was last restarted
	sf::Time timeSinceLastShot;// stores the time since the last enemy shot was fired

    sf::Vector2f DefaultPositions; //stores the default postition for the enemies
	
	sf::Vector2f offScreenPool;//stores position for an off screen pool of objects
	std::vector<int> ShootingEnemies; //holds the ID numbers for the enemies that are currently able to fire at the player
	
public:
	
	Enemy(sf::Vector2u);

	void Movement(sf::Clock& enemeyMovement);//controlls movement	
	void DrawObjectAttributes(sf::RenderWindow &window);//draws enemy sprite and enemylaser sprite
	void Die(int EnemyVectorID);//moves enemy off screen 	
	void ShootPlayer(sf::Clock& clockShootTimes);//sends out lasers from random enemies at random times
	void MoveEnemyLasers();//moves enemy lasers towards the bottom of the screen
	void ResetPositions();// resets the enemies back to their original position
	void ResetObject(); // resets all enemy attributes
	void UpdateEnemyKills();//updates how many enemies have been killed

    bool EnemyReachedBottom();//checks if an enemy has reached the bottom of the screen
	bool AllEnemiesDead();// checks if all enemies are dead
    bool bCanFunction; //bool to check if the enemies can function as normal or not

	float fEnemyStartSpeed; // stores the starting speed for enemy movement

    sf::Sprite GetSprite(int EnemyVectorID); //gets a specific enemy sprite

	std::vector<sf::Sprite> AllEnemies;// stores all enemy sprites
	std::vector<Laser> AllEnemyLasers;//holds multiple lasers for enemies 
	~Enemy();
};
#endif 