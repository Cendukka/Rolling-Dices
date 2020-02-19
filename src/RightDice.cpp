#include "RightDice.h"
#include "Game.h"

RightDice::RightDice()
{
	TheTextureManager::Instance()->load("../Assets/textures/1.png",
		"Dice1Right", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/2.png",
		"Dice2Right", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/3.png",
		"Dice3Right", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/4.png",
		"Dice4Right", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/5.png",
		"Dice5Right", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/6.png",
		"Dice6Right", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("Dice1Right");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(Config::SCREEN_WIDTH*0.75f, Config::SCREEN_HEIGHT*0.5f));
	setType(RIGHT_DICE);
}

RightDice::~RightDice()
{
	
}

void RightDice::draw()
{
}

void RightDice::draw(std::string diceID)
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;



	TheTextureManager::Instance()->draw(diceID, xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void RightDice::update()
{
}

void RightDice::clean()
{
}


