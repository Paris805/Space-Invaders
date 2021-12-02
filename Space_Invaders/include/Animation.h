#ifndef ANIMATION_H
#define ANIMATION_H
#include"SFML\Graphics.hpp"


// I would Ideally like this class to allow me to pass in an object and its
// animation and then runs through the right texture coordinates 

class Animation 
{
private:
	sf::Vector2u ufImageIndex; // holds the row of the current animation playing
	sf::Vector2u ImageCount;
	

public:
    Animation();
	void Animate(sf::Texture objectTexture);
	void Update(sf::Time detlaTime);

};

#endif
// what do I need ?
// co ordinates 
// the texture 
// something to measure the time between frames