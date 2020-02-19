/*
 **	Source file: Level1Scene
 **	Author: Samuli Lehtonen
 ** Creation date: 18.02.2020
 ** Program description: Midterm test - Web Game Programming, C++: 2 dice rolling game,
 **		pressing the roll button, the program rolls 2 dice and shows result.
 */
#pragma once

#ifndef __LEFT_DICE__
#define __LEFT_DICE__
#include "DisplayObject.h"


class LeftDice : public DisplayObject
{

public:
	LeftDice();
	~LeftDice();

	void draw() override;
	void update() override;
	void clean() override;

	void draw(std::string imageID);
private:
	
};

#endif
