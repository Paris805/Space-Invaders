#ifndef	UISCREENS_H
#define UISCREENS_H


#include <SFML\Graphics.hpp>
#include<iostream>
#include<string.h>
#include<GameState.h>

// acts as a base class for Ui screens
class UiScreens
{
protected:
	int iCurrentText;// stores the index of the current button higlighted

	//GameState gsCurrentGameState;
	

public:
	UiScreens();

    sf::Font GameFont;//stores the game font

	sf::Text MiddleButtonText;//stores the text for the middle button
	sf::Text RightButtonText;//stores the text for the right button
	sf::Text ScreenTitle;//stores the text for the title text
	sf::Text LeftButtonText;//stores the text for the left button
	
	void LoadGameFont();//loads the game font to the gamefont font variable
	void SetTextToFonts();// tets the game font to all of the texts
	void SetUpQuitText();// sets up the quit button text (right button text)
	void SetUpMiddleButtonText();// sets up the middle button text 
	void SetUpMiddleButtonText(std::string sString);// this one takes a sting to set the middle text to
	
	void SetUpLeftButtonText();//set up the left button text
	void SetUpLeftButtonText(std::string sString);// this one takes a sting to set the left text to
	void SetUpTitleText(std::string sString, int iXPosition);// sets up the title screen text
	void ButtonSwitch(sf::Event event);// controlls the button swithich mechanic
	void ChangeCurrentScreen(sf::RenderWindow& GameWindow);//change the current screen
};
#endif
