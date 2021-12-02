#include "Game.h"

Game::Game()
{

    //Open an window with the title space invaders and a close button
    Game_window = new sf::RenderWindow (sf::VideoMode(1000, 950), "Space Invaders", sf::Style::Titlebar | sf::Style::Close);

    ThePlayer = new Player(Game_window->getSize()); // creates player object and contstructs it with the window size
    Enemy0 = new Enemy (Game_window->getSize());//creates a n enemy object
    Blocade0 =  new Blockades (sf::Vector2u(800, 550), 4);// creates a blockade object
    
    EnemyMovementClock.restart(); //starts the enemy movment clock
    EnemyShootTimes.restart();// starts the enemy shoot clock
    PlayerIdleAnimation.restart();// start player animation clock

    (Game_window->setFramerateLimit(60));//sets the game window frame limit
};

void Game::GameLoop() 
{
    while (Game_window->isOpen())// while the game window is open
    {
        CheckEvents();// check for poll events

        if (!GameState::s_bInMainMenu)// the the game is not in the main menu
        {

            if (CurrentGameState.bGameIsPaused)// if the game is in its paused state
            {
                ResetGame();// reset game objects
            }
            else if (!CurrentGameState.bGameIsPaused)// if the game is not in a paused state
            {

                if (CurrentGameState.bGameOnRef) 
                {
                    MoveObjects(); // move the player, enemies and lasers

                    
                    PlayerFireCheck();// check if the players laser has hit an enemy
                    EnemyFireCheck();// check if the enemies laser has hit the player or a blockade
                   
                    ConfirmWin();// check if the player has won

                    CheckForPlayerDeath();//check if the player has lost a life
                   
                    CheckEnemyPos();// check if the enemy has reached the bottom of the screen

                    UiElements.DrawInGameScreen(*Game_window); // draw the in game screen
                }
            }

            DrawGameObjects();      
        }    

            DrawScreens();
            UpdateDisplay();
    }

};

void Game::CheckEvents()
{
    //sf::Event checkEvent;
    while (Game_window->pollEvent(checkEvent))
    {
        //if the current event is equal to closed the current open window will close
        if (checkEvent.type == sf::Event::Closed)
        {
            Game_window->close();
        }
        if (checkEvent.type == sf::Event::KeyPressed)// chekc if a key has been pressed
        {
            (*ThePlayer).InstantiateLaser(checkEvent); // intantiate laser when space button pressed

            if (CurrentGameState.bGameIsPaused)// check if the game is paused
            {
                GameState::PauseGame();// unpause the game
            }

        }
        if (!CurrentGameState.bGameOnRef)// check if the game is not running(game Over)
        {
            UiElements.GameOverText.ButtonSwitch(checkEvent);// stop enemies from functioning
            UiElements.GameOverText.ChangeCurrentScreen((*Game_window));// change the current screen acordingly
        }
        if (CurrentGameState.bhasWon)// check if the player has won
        {
            UiElements.WinScreenUI.ButtonSwitch(checkEvent);// stop enemies from functioning
        }
        if (GameState::s_bInMainMenu)
        {
            UiElements.TitleScreen.ButtonSwitch(checkEvent);// stop enemies from functioning
           
        }
    }
};

void Game::UpdateDisplay() 
{
    Game_window->display();//displayes the game window

    Game_window->clear();// clears the game window
};

void Game::DrawScreens()
{
    if (CurrentGameState.bGameIsPaused)// if the game is paused draw the paused screen
    {
        UiElements.DrawPauseScreen(*Game_window);
    }

    if (CurrentGameState.bhasWon)// if the player has won draw the win screen
    {
        UiElements.DrawWinScreen(*Game_window);

        (*Enemy0).bCanFunction = false;// stop enemies from functioning
    }
    else if (CurrentGameState.bhasLost)// otherwise the game is over draw the game over screen 
    {
        UiElements.DrawGameOverScreen(*Game_window); 
      
        (*Enemy0).bCanFunction = false;// stop enemies from functioning
    }

    if (GameState::s_bInMainMenu) // if the game is in the menu
    {
        UiElements.DrawTitleMenu(*Game_window);// draw the menu screen
    }
};

void Game::DrawGameObjects() 
{
    (*Enemy0).DrawObjectAttributes(*Game_window);//draws updated enemies onto the screen     
    (*ThePlayer).DrawObjectAttributes(*Game_window);//draws an updated player to the game window
    (*Blocade0).DrawObjectAttributes(*Game_window);// draws all blockades on to the game window  
};

void Game::ResetGame() // reset the relevent aspects of the game
{
    UiElements.Hearts.ResetLifeUI();

    (*ThePlayer).ResetObject();   

    (*Enemy0).ResetObject();

    (*Blocade0).ResetObject();
    
    UiElements.ScoreUi.UpdateScoreText((*ThePlayer).iScore);
}

void Game::MoveObjects() //move all mobable objects in the game
{ 
    (*ThePlayer).Movement(checkEvent);

    (*ThePlayer).Animate(PlayerIdleAnimation);

    (*ThePlayer).LaserTravel();// moves the player laser across the screen

    (*ThePlayer).PlayerCanShoot();// checks if the player is able to shoot

    (*Enemy0).Movement(EnemyMovementClock);  //moves the enmey incrimentally across the screen each time the clock reaches a specified number

    (*Enemy0).ShootPlayer(EnemyShootTimes);
}

void Game::UpdatePlayerLife()
{
    UiElements.Hearts.UpdateTextureRect();//update the heart ui
    (*ThePlayer).UpdateLifeState.ReduceLife();//reduce the players life
    (*ThePlayer).UpdateLifeState.Die((*ThePlayer).bIsdead);//check if the player is dead
    (*ThePlayer).UpdateLifeState.CheckForGameOver();// check if the game is over
};

void Game::PlayerFireCheck()
{
    //if player hits enemy
    for (int i = 0; i < (*Enemy0).AllEnemies.size(); i++)
    {
        //If the Plyer aser Intersects with an enemy, kill the enemy and reset the players shoot ability
        if ((*ThePlayer).GetLaser().getGlobalBounds().intersects((*Enemy0).GetSprite(i).getGlobalBounds()))
        {
            (*ThePlayer).bCanShoot = true;//player can shoot again

            (*Enemy0).Die(i);// kill enemy
            (*Enemy0).UpdateEnemyKills();// update the ammount of enemies killed
            (*ThePlayer).UpdateScore(i, 11);// update the player score
            UiElements.ScoreUi.UpdateScoreText((*ThePlayer).iScore);// update the score text
        }
    }
};

void Game::EnemyFireCheck()
{
    //if enemy hits the player
    for (int i = 0; i < (*Enemy0).AllEnemyLasers.size(); i++) // checks if the any enemy fire has hit the player or any blockades
    {
        //check if enemy has been hit 
        if ((*ThePlayer).GetSprite().getGlobalBounds().intersects((*Enemy0).AllEnemyLasers[i].GetShape().getGlobalBounds()))
        {

            (*Enemy0).AllEnemyLasers[i].ResetPosition();

            UpdatePlayerLife();

        }

        //check if a blockade is hit
        for (int j = 0; j < (*Blocade0).AllBlockades.size(); j++)// iterates through the size of the blockades
        {
            if ((*Blocade0).GetShape(j).getGlobalBounds().intersects((*Enemy0).AllEnemyLasers[i].GetShape().getGlobalBounds()))// checks if any of the blockades have been hit
            {
                (*Enemy0).AllEnemyLasers[i].ResetPosition();
                (*Blocade0).UpdateLifeState(j);
            }

        }


    }
};

void Game::ConfirmWin()
{
    //check if all enemies are dead
    if ((*Enemy0).AllEnemiesDead())
    {
        CurrentGameState.WonGame();
    }
};

void Game::CheckForPlayerDeath() // checks if the player has died
{
    if ((*ThePlayer).bIsdead)//check if the player lost a life
    {
        /* CurrentGameState.EndGame();*/
        (*Enemy0).bCanFunction = false; //stops enemy movement and shooting fuctions
        (*ThePlayer).UpdateLifeState.TemporaryDeath((*ThePlayer).bIsdead);// stops player functions for a number of seconds
    }
    else
    {
        (*Enemy0).bCanFunction = true; // allows enemy functions to continue
    }
};

void Game::CheckEnemyPos() // checks if the enemy has reached the bottom of the screen
{
    //check if the player is dead

    if ((*ThePlayer).bIsdead)//check if the player lost a life
    {
        /* CurrentGameState.EndGame();*/
        (*Enemy0).bCanFunction = false; //stops enemy movement and shooting fuctions
        (*ThePlayer).UpdateLifeState.TemporaryDeath((*ThePlayer).bIsdead);// stops player functions for a number of seconds
    }
    else
    {
        (*Enemy0).bCanFunction = true; // allows enemy functions to continue
    }


};