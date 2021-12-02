#include "ScoreUI.h"

ScoreUI::ScoreUI() 
{
	LoadGameFont();

	SetTextToFonts();	

	sScoreText = "0";
	SetUpMiddleButtonText(sScoreText);

	MiddleButtonText.setPosition(475, 20);
	MiddleButtonText.setFillColor(sf::Color::White);
	MiddleButtonText.setCharacterSize(30);

};


void ScoreUI::UpdateScoreText(int PlayerScore) // update the players score text
{
	sScoreText = std::to_string(PlayerScore);
	MiddleButtonText.setString(sScoreText);
};