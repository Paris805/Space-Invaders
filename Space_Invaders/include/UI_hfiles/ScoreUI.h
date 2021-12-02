#ifndef SCOREUI_H
#define SCOREUI_H

#include <UiScreens.h>
#include<iostream>
#include<string>

class ScoreUI:
	public UiScreens
{

public:

	ScoreUI();
	void UpdateScoreText(int PlayerScore);
	std::string sScoreText;
	
};

#endif