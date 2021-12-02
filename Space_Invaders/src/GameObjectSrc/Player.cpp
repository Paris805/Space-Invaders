#include "Player.h"
#include <SFML\Graphics.hpp>


Player::Player(sf::Vector2u windowSize) 
{

    iScore = 0; // sets the current score for the player
 
    iCurrentLife = kiMaxLifeAmmount;// sets the current life to the max life (3)
    iIdleCUrrentFrame = 0; // sets the current idle frame to 0;
    
    bCanShoot = true;// sets the shoot bool to true so the player can shoot when entering the game
    bIsdead = false; // sets the dead bool to false

    DefaultPlayerPosition = sf::Vector2f(windowSize.x / 2, 760); // sets the starting position of the player

    LeftSideBoundary = (sf::Vector2f(100, 0));//sets the left screen side boundary
    RightSideBoundary = (sf::Vector2f(900, 0)); // sets the right screen side bondary
   
    loadObjectTexture("Textures/ship hover.png");// load the player texture
    iYOrigin = ObjectSprite.getOrigin().y;// set the y sprite origin to the right area
    SetUpSprite(150); // set up the player object sprite

    // set all the idle animation frames to a specific int rect
    IdleFrames[0] = sf::IntRect(0, 0, 32, 32);
    IdleFrames[1] = sf::IntRect(32, 0, 32, 32);
    IdleFrames[2] = sf::IntRect(0, 32, 32, 32);
    IdleFrames[3] = sf::IntRect(32,32, 32, 32);
    IdleFrames[4] = sf::IntRect(0, 64, 32, 32);
    IdleFrames[5] = sf::IntRect(32, 64, 32, 32);
    IdleFrames[6] = sf::IntRect(0, 98, 32,32);
    IdleFrames[7] = sf::IntRect(32, 98, 32, 32);
    

    Laser playerLaser(sf::Vector2f(windowSize.x, windowSize.y + 10)); // creates a laser and and sets the offscreen pool position
    PlayerLaser = playerLaser;
    AnimateCLock.restart();//restsert the animation clock
    AnimationTimeFrame = AnimateCLock.getElapsedTime();//assigns the elapesd animation clock 

   // ObjectSprite.setOrigin((playerShipScale.x / 4)/ObjectSprite.getScale().x , ObjectSprite.getOrigin().y);//setcs the origin to the top of the ship where the gun is

    ObjectSprite.setPosition(DefaultPlayerPosition);// sets the player sprite postition to the default player position

};

void Player::Animate(sf::Clock &Time ) 
{
    AnimationTimeFrame = Time.getElapsedTime();//assigns the elapesd animation clock 

    if (AnimationTimeFrame.asSeconds() > 1 *(1.0f/8.0f)) //check if the frame rate for the animation ahs met 
    { 
        iIdleCUrrentFrame += 1;// increment the animation frame

        if (iIdleCUrrentFrame >= s_kiIdleFrameSize) // if the current frome is bigger than the size of the array 
        {
            iIdleCUrrentFrame = 0; // restet back to the first frame
        }
        ObjectSprite.setTextureRect(IdleFrames[iIdleCUrrentFrame]);//st the sprite to correct frame 
       
        Time.restart();// reset the animation
    }

}

void Player::Movement(sf::Event event)
{
    if (!bIsdead) {
        
        

        if (ObjectSprite.getPosition().x < RightSideBoundary.x) //check if the player has not met the right side boundary point
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))// check if the right arrow key has been pressed
            {
                ObjectSprite.move(sf::Vector2f(iSpeed, 0));//move the ship to the right side of screen
            }
        }

        
        if (ObjectSprite.getPosition().x > LeftSideBoundary.x)//check if the player has not met the left side boundary point
        {
           if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))// check if the left arrow key has been pressed
            {
                ObjectSprite.move(sf::Vector2f(-iSpeed, 0));//move the ship to the left side of the screen
            }
        }
    }

};

 sf::Sprite Player::GetSprite()// return the player sprite
 {  
     return ObjectSprite;
 };

 sf::RectangleShape Player::GetLaser()// return the player laser
 {
     return PlayerLaser.GetShape();
 };

void Player::DrawObjectAttributes(sf::RenderWindow &window)// draw all of the player attributes
{
    window.draw(ObjectSprite);
    PlayerLaser.Draw(window);
};

void Player::InstantiateLaser(sf::Event event) // sets the player laser position to the player position when the space bar is pressed
{
    if (!bIsdead && bCanShoot)// checks if the player is alive and can shoot
    {
        if (event.key.code == sf::Keyboard::Space)// checks if the space bar has been pressed
        {         
            PlayerLaser.SetPosition(ObjectSprite.getPosition());// sets the position of the laser to the current sprite position
            bCanShoot = false; // set the shoot bool to false
        }
    }
   
};
void Player::LaserTravel() // moves the laser across the screen
{
    if (!bCanShoot) // checks if the player can not shoot // if not ths means the laser has been fired 
    {
        PlayerLaser.Move(-10);// move the laser towards the top half of the screen
    }
    else //if the player can shoot
    {
        PlayerLaser.ResetPosition();// reset the laser postision (somwhere off screen)
    }
    
}
void Player::PlayerCanShoot() // determines if the player can shoot
{
    if (PlayerLaser.GetPosition().y <= 20)//if the laser reaches the top part of the screen
    {
        bCanShoot = true;// the player can shoot again
    }   
    // if not the player can not shoot
};


void Player::ResetObject() // reset the player object attributes
{
    ObjectSprite.setPosition(DefaultPlayerPosition);
    UpdateLifeState.ResetPlayerLife();
    iScore = 0;
}

void::Player::UpdateScore(int currentEnemyID, int EnemyQuantity)// updates the players score depending on which enemy it has hit
{
    int offset = 10;//
    for (int i= 0; i < 5; i++)// for the length if how many enemy rows there are (5)
    {
        if (currentEnemyID >= (i * EnemyQuantity) && currentEnemyID <= (i * EnemyQuantity) + offset) // finds out what row the current enemy is in
        {
            switch (i)// add a specific number of points dependin on what row the enemy lies in
            {
            case 0:// last row
                iScore += 30;
                break;

            case 1: 
                iScore += 20;
                break;

            case 2: 
                iScore += 20;
                break;

            case 3: 
                iScore += 10;
                break;

            case 4:// first row
                iScore += 10;
                break;

            default:
                break;
            }
        }
    }
}