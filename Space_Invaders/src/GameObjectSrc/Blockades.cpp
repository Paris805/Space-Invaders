#include "Blockades.h"

//Blockades::Blockades() {};

Blockades::Blockades(sf::Vector2u position, int BlockAdeAMount)
{
	
	iBlockadeAmmount = BlockAdeAMount; //sets the ammount of blockades you want to show on screen

	blockXPostition = position;// sets the blocade x positio

	iYOrigin = 0;// stores the y axis of the sprite origin



	loadObjectTexture("Textures/BlockadeSpriteSheet.png");//loads the object texture (see gameObject class for more)
	SetUpSprite(50);//sets up the basic aspects of the object sprite see game object class for more

	ObjectSprite.setScale(3, 2);// set the objext sprite scale
	ObjectSprite.setOrigin(50 / ObjectSprite.getScale().x, iYOrigin);// set th object sprite origin

	textureRect = ObjectSprite.getTextureRect();// set the variable texture rect equal to the starting texture rect

	for (int i = 0; i < iBlockadeAmmount; i++) // this loop adds blockade sprites to the blockade vector and sets their position
	{
		AllBlockades.push_back(ObjectSprite);// add sprite
		AllBlockades[i].setPosition(sf::Vector2f(position.x / iBlockadeAmmount + (position.x / iBlockadeAmmount * i), 675));// set sprite position
		
	}

};
void Blockades::DrawObjectAttributes(sf::RenderWindow& window) // draws the blockades to the screen
{
	for (int i = 0; i < iBlockadeAmmount; i++) 
	{
		window.draw(AllBlockades[i]);
	}
	
};

sf::Sprite Blockades::GetShape(int &iShapeIDNumber) // this returns the requested blockade acording to its id number
{
	return AllBlockades[iShapeIDNumber];
};
void Blockades::UpdateLifeState(int& iShapeIDNumber)// this updates the current texture rect of a blockade that has been hit
{
	sf::IntRect holdTexture = AllBlockades[iShapeIDNumber].getTextureRect();// stores the current texture rect of the hit blockade
	holdTexture.left += 98; // incriments the left value of the tecture rect

	if (holdTexture.left >= 128)// checks if the current texture rect is out of scope (which means the blockade has been destroyed)
	{
		AllBlockades[iShapeIDNumber].setPosition(1000, 1000);//sets the position of the blockade off screen so the enemy can not hit an invisible object
	}
	else
	{
		AllBlockades[iShapeIDNumber].setTextureRect(holdTexture);// set the texture rect to the new texture rect
	}
	
};

void Blockades::ResetObject()// reset the blockade object attriburtes
{	

	for (int i = 0; i < iBlockadeAmmount; i++) // reset all blocks to original position
	{		
		AllBlockades[i].setTextureRect(textureRect);//reset all blocks texture rect
		AllBlockades[i].setPosition(sf::Vector2f(blockXPostition.x / iBlockadeAmmount + (blockXPostition.x / iBlockadeAmmount * i), 675));// reset the position of the blockades
	}
}
Blockades::~Blockades() {};