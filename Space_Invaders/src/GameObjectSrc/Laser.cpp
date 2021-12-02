#include <Laser.h>

Laser::Laser() {};
Laser::Laser(sf::Vector2f spawnPosition)//the constructor 
{
	bBottomBoundary = 690;// sets the bottom screen boundary
	fTopBoundary = 25;// sets the top screen boundary
	PoolPosition = spawnPosition;// sets the pool postition to the spawn position

	laserShape.setSize(sf::Vector2f(5, 15));// sets the size of the laser
	laserShape.setPosition(PoolPosition); // sets the position of the laser
	laserShape.setFillColor(sf::Color::Red);// sets the color of the laser
	
};

sf::RectangleShape Laser::GetShape() 
{
	return laserShape;
};
sf::Vector2f Laser::GetPosition() 
{
	return laserShape.getPosition();
};
void Laser::SetPosition(sf::Vector2f newPosition) 
{
	laserShape.setPosition(newPosition);
};

void Laser::Move(int Direction) 
{
		laserShape.move(0, Direction);
};

void Laser::Draw(sf::RenderWindow &window) 
{
	window.draw(laserShape);
}

void Laser::ResetPosition() 
{
	laserShape.setPosition(PoolPosition);
};

void Laser::ResetPosition(sf::Vector2u &WindowPosition)
{
	if (laserShape.getPosition().y <= WindowPosition.y) 
	{
		laserShape.setPosition(PoolPosition);
	}
	
};