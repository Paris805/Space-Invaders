#include "gameObject.h"
#include <SFML\Graphics.hpp>


void gameObject::loadObjectTexture(std::string sfileName) //loads an Texture and sets it to the object texture 
{
	ObjectTexture.loadFromFile(sfileName);
}; 

void gameObject::SetUpSprite(float fSize)// sets up the object sprite
{
	
	iSpriteRows = ObjectTexture.getSize().y / s_kiIndividualSpriteSize;// refers to the number of rows in the sprite

	ObjectSprite.setTexture(ObjectTexture);// sets the texture to the sprite
	ObjectSprite.setTextureRect(sf::IntRect(0, 0,32, 32));// sets the tecture rect to the first image in the sprite
	ObjectSprite.setScale(fSize/ObjectTexture.getSize().x , (fSize*2) / ObjectTexture.getSize().y);// sets the scale of the sprite acoring to the size given
	ObjectSprite.setOrigin((fSize / iSpriteRows) / ObjectSprite.getScale().x, iYOrigin);// sets the origin of the sprite to make sure the it is places on the screen correctly
	
};