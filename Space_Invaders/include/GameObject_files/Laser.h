#ifndef LASER_H
#define LASER_H

#include"SFML\Graphics.hpp"
#include <iostream>

class Laser
{
protected:
	sf::RectangleShape laserShape;// creates a rectangle shape

	sf::Vector2f PoolPosition;// stores an off screen pool position

	float fTopBoundary = 0; //holds the y co-ordinate for the top screen boundary
	float bBottomBoundary = 0;// holds the y co-ordinate for the bottom screen boundary

public:

	Laser();
	Laser(sf::Vector2f spawnPosition);

	sf::RectangleShape GetShape();//gets the shape of the laser

	sf::Vector2f GetPosition();// gets the position of the laser

	void SetPosition(sf::Vector2f newPosition); //sets the laser postion to a new position
	void ResetPosition(); // resets laser position back to default position
	void ResetPosition(sf::Vector2u& WindowPosition); //resets position if limit is passed
	void Move(int Direction); //moves the laser in a specific direction
	void Draw(sf::RenderWindow &window);//draw the laser to the game windw

	
};
#endif
