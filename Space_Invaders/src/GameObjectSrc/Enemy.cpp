#include <Enemy.h>

bool Enemy::s_bBoundaryReached = false;
int Enemy::s_iCurrentDirection = 20; // current direction is right

Enemy::Enemy(sf::Vector2u windowSize) // constructor:holds the preloaded part 
{
    iStartXPos = 300; // sets the X starting position to 300
    fEnemyStartSpeed = 1;//sets the starting speed to 1 
    iEnemiesKilled = 0; // sets the amount of enemies killed to 0
    icurrentEnemyLaser = 0;// sets the current enemy laser to 1
    iStartDelay = 3; // sets the start delay of enemies shooting to 3, enemies wont start shooting until after 3 seconds
    iYOrigin = 18;// sets the y origin of the enemy sprite to 18
    
    fCurrentSpeed = fEnemyStartSpeed; // sets the current enemy speed to the start speed
    
    bCanFunction = true; //sets the function of the enemies to true so they can work as usual

    DefaultPositions = sf::Vector2f(iStartXPos, (windowSize.y/10) * 2 + 60); // sets the default postition
    sf::Vector2f updatedPosition = DefaultPositions; // a Variable used to store the default position that can later be altered witout effecting the default position
     
    srand(time(0));//sets the random time to the time of the os 
   
    loadObjectTexture("Textures/Enemies.png"); //loads the object texture (see gameObject.cpp for more)
    SetUpSprite(64);// sets up the sprite of the enemy (see gameObject.cpp for more)
   
    offScreenPool = (sf::Vector2f(windowSize.x*2, 10));// sets the off screen pool
    LeftSideBoundary =(sf::Vector2f(100, ObjectSprite.getPosition().y)); // sets the screen boundaires
    RightSideBoundary =(sf::Vector2f(900, ObjectSprite.getPosition().y));

    Laser EnemyLaser(offScreenPool);// creates a laser object

    //This loop stores:
    //enemies into a vector
    //lasers into a vectoe
    //and enemy IDs into a vector to enable shooting ablility

    for (int i = 0; i < kiNumberOfEnnemyRows; i++) //for the number of enemy rows which is 5
    {
        for (int j = 0; j < ks_iNumberOfEnemies; j++)  //for the number of enemies in a row which is 11
        {
            AllEnemies.push_back(ObjectSprite); //add a sprite to the enemy vector
            AllEnemies[j + (i * ks_iNumberOfEnemies)].setPosition(updatedPosition);//set the next correct postion (j+i*11)

            updatedPosition.x += kvSpaceBetween.x; // incriment the x position so the next enemy will appear next to the previous one


            // this is responsible for storing the ID numbers of the first row of enemies (closest to the player)
            if (i == 4) 

            {   AllEnemyLasers.push_back(EnemyLaser);// adds a laser shape to a vector that holds all lasers           
                ShootingEnemies.push_back( j + (i * ks_iNumberOfEnemies));// stores the id Numbers of the first row of enemies (j+ i* 11)
            }
        }
        updatedPosition.x = iStartXPos; // updates the x postion back to the original set position so the next set of enemies line up with the first

        updatedPosition.y += kvSpaceBetween.y;// updates the y postion to lower than the last set of enemies 

        
    }
};


void Enemy::Movement(sf::Clock &clockEnemyMovement) 
{    

    if (bCanFunction) //checks if the enemy is alowed to function as usual
    {
       
        timeSinceLastRestart = clockEnemyMovement.getElapsedTime();// stores the elapsed time 

        if (timeSinceLastRestart.asSeconds() >= fCurrentSpeed)// checks if the elapsed time is equal to the current speed of the enemies
        {

            //this loop checks if an enemy has reached a boundary point

            for (int i = 0; i < AllEnemies.size(); i++) // for the lenght of the enemy vector (55)
            {
                            
                if (AllEnemies[i].getPosition().x == RightSideBoundary.x) //check if the enemy has reached the right side boundary
                {
                    s_bBoundaryReached = !s_bBoundaryReached;//switched the boundary bool between true and false depending on its last state (this is so when the enemy gets triggered to move down, it does not continue to do so since it has reached that boundary)

                    s_iCurrentDirection = -iRight;//Changes the characters direction to the left

                    break; // breaks the loop as soon as 1 enemy has reached the boundary
                }
                else if (AllEnemies[i].getPosition().x == LeftSideBoundary.x)
                {
                    s_bBoundaryReached = !s_bBoundaryReached;  //switches boundary bool between true and false depending on is last state

                    s_iCurrentDirection = iRight; // changes the characters direction to the right

                    break;// breaks the loop as soon as 1 enemy has reached the boundary
                }
            }

            
            if(!s_bBoundaryReached)// if the boundary has not been reached All enemies continue to move as normal
            {
                for (int k = 0; k < AllEnemies.size(); k++)// for the length of the enemy vector (55)
                {
                    
                    AllEnemies[k].move(sf::Vector2f(s_iCurrentDirection, 0));// move each enemey in the current direction

                   //reset the two boundaries to the right position
                    LeftSideBoundary.y = ObjectSprite.getPosition().y; 
                    RightSideBoundary.y = ObjectSprite.getPosition().y;                 
                }
            }
            else // otherwise if the boundary has been reached move all enemies down
            {
                for (int k = 0; k < AllEnemies.size(); k++) // for the length of the enemy vector(55)
                {
                    
                    AllEnemies[k].move(sf::Vector2f(0, 20));// loop through all enemies and move them down by 20
                                    
                }
                
                fCurrentSpeed -= kfSpeedIncrease;// increase the enemey speed         
            } 
            
            clockEnemyMovement.restart();// restart the movement clock
                     
        }

    } 
    
  
};

void Enemy::DrawObjectAttributes(sf::RenderWindow &window) //Draws the attribues of the enemy to the game window

{
    //this loop draws all enemies to the render window
    for (int i = 0; i < AllEnemies.size(); i++) 
    {
        window.draw(AllEnemies[i]);
    }

    //this loop draws all enemy lasers to the render window
    for (int j = 0; j < AllEnemyLasers.size(); j++)
    {
        AllEnemyLasers[j].Draw(window);
    }
    
};

sf::Sprite Enemy::GetSprite(int EnemyVectorID) // alows us to get the shape to check for bounding box
{
    return AllEnemies[EnemyVectorID]; // returns a specific enemy shape based on the enemy vector id passed through
};

void Enemy::Die(int EnemyVectorID)
{
    AllEnemies[EnemyVectorID].setPosition(offScreenPool); // puts the enemy hit in a pool offscreen

    CheckEnemyShootStaus(EnemyVectorID);//checks and updates the enemy current enemy shoot status
};

void Enemy::CheckEnemyShootStaus(int &EnemyVectorID) //the enemy ID in this case refers to the enemy that has just died 
{  
    for (int i = 0; i < ShootingEnemies.size(); i++) // for the length of enemeies that are allowed to shoot (11)
    {
        if (ShootingEnemies[i] == EnemyVectorID) //if the enemy that died was an enemy with shooting abilities
        {
             // updates the shooting enemy to an enemy that is still alive (on screen)

            if (ShootingEnemies[i] >= 10) // if the value is bigger than 10 (if the enemy is not on the row furthest away from the player)
            {
                
                ShootingEnemies[i] -= ks_iNumberOfEnemies; //A new Enemy ID is calculated (enemy above newest dead enemy is given shooting abilities)
               
                
                while (ShootingEnemies[i] > 10) // if the enemy is not on the last row (furthest from the player)

                {
                    if (AllEnemies[ShootingEnemies[i]].getPosition().x >= offScreenPool.x/2)// if the next enemy above is off screen 
                    {
                        ShootingEnemies[i] -= ks_iNumberOfEnemies;   // then choose the enemy above to shoot the player
       
                    }
                    else
                    {
                        break;//break out of loop if the enemy is on screen
                    }
                    if (ShootingEnemies[i] <= 11) { break; }
                }
                
            }
            
            break;
        }
    }

};

int Enemy::iPickTimeDelay()// picks a random time delay from the last bullet
{
    int limit = (rand() % 3) + 1;

    return limit;
};

int Enemy::iPickFiringEnemy()//picks a random enemy from the shootable vector
{
    int limit = (rand() % (ShootingEnemies.size()-1)) + 0;

    return limit;
};

void Enemy::ShootPlayer(sf::Clock &clockShootTimes)
{
    MoveEnemyLasers();// moves the enemy lasers towards the bottom of the screen 
    timeSinceLastShot = clockShootTimes.getElapsedTime();
    if (bCanFunction) {
        if (timeSinceLastShot.asSeconds() >= iStartDelay)//checks if the elapesd tiem is equal to the start delay which is 3
        {
           
            if (icurrentEnemyLaser >= AllEnemyLasers.size() - 1)//checks the laser picked is within bounds 
            {
                icurrentEnemyLaser = 0;// the next laser in line is the first again
            }
            else
            {
                icurrentEnemyLaser += 1;//so the next laser in line gets picked
            }
            
            int nextENemy = ShootingEnemies[iPickFiringEnemy()];// picks the next eligable enemy at random

            sf::Vector2f nextPosition = AllEnemies[nextENemy].getPosition();//the next position (for the laser) is set to the next enemy.

            AllEnemyLasers[icurrentEnemyLaser].SetPosition(nextPosition);//the current lasers postition is then set to the next enemy that will shoot at the player
           
            iStartDelay = iPickTimeDelay();// the start delay time is set to a new time (1-3 seconds)

            clockShootTimes.restart(); // The shooting time clock is restarted
        }
    }
};

void Enemy::MoveEnemyLasers() //move lasers across the screen
{
    int iLaserSpeed = 5; // sets the enemy laser speed to 5

    for (int i = 0; i < AllEnemyLasers.size(); i++) // for the lenghth of the laser array which is 11
    {
        AllEnemyLasers[i].Move(iLaserSpeed); // move the current enemy laser 
    }

};

void Enemy::ResetPositions() //reset the enemy positions and other enemy attributes
{
    sf::Vector2f updatedPosition = DefaultPositions;//resets the updated position back to the default position

    fCurrentSpeed = fEnemyStartSpeed; //resets the movement speed

    s_bBoundaryReached = false; // sets the boundary bool to false

    iEnemiesKilled = 0; // sets the ammout of enemies killed to 0

    //this loop resets the enemy positions and the shooting enemies

    for (int i = 0; i < kiNumberOfEnnemyRows; i++) 
    {
        for (int j = 0; j < ks_iNumberOfEnemies; j++)//for the number of enemies in a row which is 11
        {
            AllEnemies[j + (i * ks_iNumberOfEnemies)].setPosition(updatedPosition);// set the current enemies possition to the updated position
            updatedPosition.x += kvSpaceBetween.x; // incrment the updated positions x axis

            if (i == 4)// this is responsible for storing the ID numbers of the first row of enemies
            { 
              
                ShootingEnemies[j]=(j + (i * ks_iNumberOfEnemies));// stores the id Numbers of the first row of enemies
            }
        }
        updatedPosition.x = iStartXPos; // reset the x axis starting position
        updatedPosition.y += kvSpaceBetween.y;// incriment the yaxis updated posotion so the next lot of enemies appear lower than the last
    }  
}

bool Enemy::EnemyReachedBottom() // checks if an enemy has reached the bottom of the screen, returns true if so
{
    for (int i = 0; i < AllEnemies.size(); i++)
    {
        if (AllEnemies[i].getPosition().y >= 760) 
        {
            return true;       
        }
    }
    return false;
};

bool Enemy::AllEnemiesDead() // checks if all enemies have been killed, if do it returns true
{
    if (iEnemiesKilled >= iTotalEnemies) 
    {
        return true;
    }
    else{ return false; }
}

void Enemy::UpdateEnemyKills() // increments the ammount of current enemies that are dead
{
    iEnemiesKilled += 1;
};

void Enemy::ResetObject()//resets the object for restarting the game
{
    ResetPositions();
    //reset other things like 
    //animation
    //iEnemiesKilled = 0;
};

Enemy::~Enemy() {};