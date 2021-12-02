#ifndef BLOCKADES_H
#define BLOCKADES_H

#include<SFML\Graphics.hpp>
#include <iostream>
#include<vector>
#include<gameObject.h>

class Blockades:
	public gameObject
{
private:
	Blockades();//default constructor
		
	sf::Vector2u blockXPostition;// stores the x postion of the blockades
	
	sf::IntRect textureRect;// stores the starting texure rect of the sprite

public:

	Blockades(sf::Vector2u, int BlockAdeAMount);

    int iBlockadeAmmount;

	void DrawObjectAttributes(sf::RenderWindow &window);// Draws all visual attributes of the blocades to the screen
	void ResetObject();//Resets the blocade back to its starting form
	void UpdateLifeState(int& iShapeIDNumberd);// updates the texture rect to its new current life state

	std::vector<sf::Sprite> AllBlockades;// stores all the blockades in a vector
	
	sf::Sprite GetShape(int &iShapeIDNumber);// gets a specific blocade from the vector

	~Blockades();
};

#endif