#include "LeftDice.h"
#include "Game.h"

LeftDice::LeftDice()
{
	TheTextureManager::Instance()->load("../Assets/textures/1.png",
		"Dice1Left", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/2.png",
		"Dice2Left", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/3.png",
		"Dice3Left", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/4.png",
		"Dice4Left", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/5.png",
		"Dice5Left", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/6.png",
		"Dice6Left", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("Dice1Left");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.25f, Config::SCREEN_HEIGHT * 0.5f));
	setType(LEFT_DICE);
}

LeftDice::~LeftDice()
{
}

void LeftDice::draw()
{
}
void LeftDice::draw(std::string diceID)
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;



	TheTextureManager::Instance()->draw(diceID, xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void LeftDice::update()
{
}

void LeftDice::clean()
{
}
