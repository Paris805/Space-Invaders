#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "SFML\Graphics.hpp"
#include <string>

class gameObject // this class is the base class for all game objects (enemies, player, blockades)
{
protected: 	
	int iSpriteRows;// stores the amount of rows in the sprite png 
	int iYOrigin;// holds the value of the y origin for the sprite
	static const int s_kiIndividualSpriteSize = 32;//stores the set individual sprit size

	sf::Vector2f LeftSideBoundary;//holds the enemies bondaries
	sf::Vector2f RightSideBoundary;

	sf::Texture ObjectTexture;//stores the object texture 

	sf::Sprite ObjectSprite;//stores the object sprite
public:
	virtual void ResetObject() = 0; // a function for reseting objects
	virtual void DrawObjectAttributes(sf::RenderWindow &window) = 0;// a function for darwing all of the objects attributes to the window

	void loadObjectTexture(std::string sfileName);//loads the objexts texture to the game
	void SetUpSprite(float iSize);// sets up specific sprite elements so it appears in the game properly

	

};
#endif