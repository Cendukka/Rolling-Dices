/*
 **	Source file: Level1Scene
 **	Author: Samuli Lehtonen
 ** Creation date: 18.02.2020
 ** Program description: Midterm test - Web Game Programming, C++: 2 dice rolling game,
 **		pressing the roll button, the program rolls 2 dice and shows result.
 */
#pragma once
#ifndef __LEVEL_1_SCENE__
#define __LEVEL_1_SCENE__

#include "Scene.h"
#include "Label.h"
#include "Rollbutton.h"
#include "LeftDice.h"
#include "RightDice.h"
#include "Dices.h"

class Level1Scene : public Scene
{
public:
	Level1Scene();
	~Level1Scene();
	
	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;

	// getters
	glm::vec2 getMousePosition();

	void initializeLabels();
	//Functions for throwing dices, checking the dices
	void throwDices();
	void checkLeftDiceNumber(int leftDice);
	void checkRightDiceNumber(int rightDice);

private:

	//strings to show on labels
	std::string m_pLeftDiceString;
	std::string m_pRightDiceString;
	std::string m_pResultString;

	//random numbers for the dices and the sum
	int m_pRandDiceLeft = 0;
	int m_pRandDiceRight = 0;
	int m_pResultInt = 0;
	
	// game objects
	RollButton* m_pRollButton;
	LeftDice* m_pLeftDice;
	RightDice* m_pRightDice;
	//labels

	Label* m_pLeftDiceLabel;
	Label* m_pRightDiceLabel;
	Label* m_pResultLabel;

	//initialize values for the dices
	std::string m_leftDiceImage = "Dice6Left";
	std::string m_rightDiceImage = "Dice6Right";
	

	// private data member
	glm::vec2 m_mousePosition;

	 
	
};

#endif /* defined (__LEVEL_1_SCENE__) */
