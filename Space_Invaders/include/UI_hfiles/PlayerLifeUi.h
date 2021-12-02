#ifndef PLAYERLIFEUI_H
#define PLAYERLIFEUI_H

#include<iostream>
#include<SFML\Graphics.hpp>



class PlayerLifeUi
{
private:
	sf::Texture HeartUITexture;
	

public:

	PlayerLifeUi();
	
	void UpdateTextureRect();// updated the current texture rect
	void ResetLifeUI();//resets the life ui to full 3 hearts
	
    sf::RectangleShape HeartUIShape;
};

#endif