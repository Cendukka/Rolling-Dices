/*
 **	Source file: Rollbutton.h
 **	Author: Samuli Lehtonen
 ** Creation date: 18.02.2020
 ** Program description: Midterm test - Web Game Programming, C++: 2 dice rolling game,
 **		pressing the roll button, the program rolls 2 dice and shows result.
 */
#pragma once


#ifndef __ROLL_BUTTON__
#define __ROLL_BUTTON__
#include "Button.h"


class RollButton : public Button
{
public:

	RollButton();
	~RollButton();

	//getters
	int getOnlyRegisterClickOnce();

	//Setters
	void setOnlyRegisterClickOnce(int clickFlag);

	bool ButtonClick() override;
	
private:

	bool m_isClicked;
	int m_pClickFlag;
	
};


#endif
