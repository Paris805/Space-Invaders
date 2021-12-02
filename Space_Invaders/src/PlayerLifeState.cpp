#include "PlayerLifeState.h"



PlayerLifeState::PlayerLifeState()
{
    iCurrentLife = MaxLifeAmmount;
    iDeathLength = 2;

    DeathClock.restart();// starts the death clock
};



void PlayerLifeState::ReduceLife()
{  
    iCurrentLife -= 1;    
}

void PlayerLifeState::Die(bool& isDead)
{
    isDead = true;
    DeathClock.restart();
};

void PlayerLifeState::TemporaryDeath(bool& isDead)
{

    sf::Time ElapsedTime = DeathClock.getElapsedTime(); // gets the elapsed time of players death
    if (isDead) // checks if the player is dead
    {
        std::cout << ElapsedTime.asSeconds()<<std::endl;
        if(ElapsedTime.asSeconds()>iDeathLength) // checks if the elapsed time has met the 
        {
            isDead = false; //once the time has been met isDead is set back to false so the player can continue functioning as normal.
            DeathClock.restart(); // the death clock us restarted
           
        }
    }
     
};

void PlayerLifeState::CheckForGameOver()
{
    if (iCurrentLife <= 0)
    {
        GameState::EndGame();
       
    }
};

void PlayerLifeState::ResetPlayerLife() 
{
    iCurrentLife = MaxLifeAmmount;
};