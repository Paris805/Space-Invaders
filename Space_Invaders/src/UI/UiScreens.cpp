#include "UiScreens.h"
//see.h file for rough information on what the functions do
UiScreens::UiScreens() 
{
	
	iCurrentText = 1;
};

void UiScreens::LoadGameFont()
{
	GameFont.loadFromFile("Fonts/8-BIT WONDER.TTF");//loads the game font to the gamefont font variable
};
void UiScreens::SetTextToFonts()
{
	LeftButtonText.setFont(GameFont);
	MiddleButtonText.setFont(GameFont);
	RightButtonText.setFont(GameFont);
	ScreenTitle.setFont(GameFont);
};

void UiScreens::SetUpQuitText() 
{	
	RightButtonText.setPosition(800, 875);
	RightButtonText.setFillColor(sf::Color::White);
	RightButtonText.setString("Quit");
	RightButtonText.setCharacterSize(20);
}

void UiScreens::SetUpMiddleButtonText()
{	
	MiddleButtonText.setPosition(410, 875);
	MiddleButtonText.setFillColor(sf::Color::Green);
	MiddleButtonText.setString("Play Again");
	MiddleButtonText.setCharacterSize(20);
};

void UiScreens::SetUpLeftButtonText()
{	
	LeftButtonText.setPosition(100, 875);
	LeftButtonText.setFillColor(sf::Color::White);
	LeftButtonText.setString("Menu");
	LeftButtonText.setCharacterSize(20);
};

void UiScreens::SetUpMiddleButtonText(std::string sString) 
{	
	MiddleButtonText.setPosition(410, 875);
	MiddleButtonText.setFillColor(sf::Color::Green);
	MiddleButtonText.setString(sString);// sets the string to the sString
	MiddleButtonText.setCharacterSize(20);
};
void UiScreens::SetUpLeftButtonText(std::string sString)
{
	LeftButtonText.setPosition(100, 875);
	LeftButtonText.setFillColor(sf::Color::White);
	LeftButtonText.setString(sString);// sets the string to the sString
	LeftButtonText.setCharacterSize(20);
};
void UiScreens::SetUpTitleText(std::string sString, int iXPosition) 
{
	ScreenTitle.setPosition(iXPosition, 100);// sets the specified x position of the title 
	ScreenTitle.setFillColor(sf::Color::Yellow);
	ScreenTitle.setOutlineColor(sf::Color::Black);
	ScreenTitle.setOutlineThickness(5);
	ScreenTitle.setString(sString);// sets the specified string for the title
	ScreenTitle.setCharacterSize(55);
};

void UiScreens::ButtonSwitch(sf::Event event) // switch between buttons in a menu
{
	
	
	//set the correct fill colour to the current selected button
	switch (iCurrentText)
	{
	case 1:
		MiddleButtonText.setFillColor(sf::Color::Green);
		LeftButtonText.setFillColor(sf::Color::White);
		RightButtonText.setFillColor(sf::Color::White);
		break;

	case 2:
		RightButtonText.setFillColor(sf::Color::Green);
		MiddleButtonText.setFillColor(sf::Color::White);
		LeftButtonText.setFillColor(sf::Color::White);
		break;
	case 0:
		LeftButtonText.setFillColor(sf::Color::Green);
		RightButtonText.setFillColor(sf::Color::White);
		MiddleButtonText.setFillColor(sf::Color::White);
		break;

	default:
		break;
	}
	
	//increment  or decrement the current text index depending on which button is pressed
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) // incriment if the right arrow key is pressed
	{
		iCurrentText += 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))// decrement if the left arrow key is pressed
	{
		iCurrentText -= 1;
	}
	
	if (iCurrentText < 0)
	{
		iCurrentText = 0;
	}
	else if (iCurrentText > 2)
	{
		iCurrentText = 2;
	}
	
	

}

void UiScreens::ChangeCurrentScreen(sf::RenderWindow& GameWindow) 
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) // changes to the corresponding screen when the enter button is pressed
	{
		//swtich to the correct screen
		switch (iCurrentText)
		{
		case 1: //Play or Play again
			std::cout << "play again button was pressed \n";
			GameState::PauseGame();
			break;

		case 2:// quit game
			GameWindow.close();

			break;
		case 0:// go to menu
			std::cout << "menu button was pressed \n";
				GameState::EnableMenu();
			
			break;

		default:
			break;
		}
		

		

	}
	
};