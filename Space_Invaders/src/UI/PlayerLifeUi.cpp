#include "PlayerLifeUi.h"


PlayerLifeUi::PlayerLifeUi() {

	// sets up the heart ui
	HeartUIShape.setPosition(sf::Vector2f(10, 10));
	HeartUIShape.setSize(sf::Vector2f(160, 80)); // set thesize of the ui element

	HeartUITexture.loadFromFile("Textures/Basic Heart.png");// loat the correct texture from files

	HeartUIShape.setTexture(&HeartUITexture);// set the loaded texture to the shape   
	HeartUIShape.setTextureRect(sf::IntRect(0, 0, 64, 32));
};


void PlayerLifeUi::UpdateTextureRect()// updates the heart ui texture rect
{

	sf::IntRect currentRect = HeartUIShape.getTextureRect();
	currentRect.top += 32;// increment the top rect 
	HeartUIShape.setTextureRect(currentRect);// set the sprite to the right rect

};


sf::IntRect currentTextureRect(sf::RectangleShape &shape)
{
	return shape.getTextureRect();//return the texture coordinates of a shape
};



void PlayerLifeUi::ResetLifeUI() 
{
	HeartUIShape.setTextureRect(sf::IntRect(0, 0, 64, 32));
}
