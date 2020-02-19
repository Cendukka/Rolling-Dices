

#include "Level1Scene.h"
#include "Game.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

Level1Scene::Level1Scene()
{
	start();
}

Level1Scene::~Level1Scene()
{
}
//Draw all labels and gameobjects
void Level1Scene::draw()
{
	m_pRollButton->draw();
	m_pLeftDice->draw(m_leftDiceImage);
	m_pRightDice->draw(m_rightDiceImage);
	m_pLeftDiceLabel->draw();
	m_pRightDiceLabel->draw();
	m_pResultLabel->draw();
}

void Level1Scene::update()
{
	m_pRollButton->setMousePosition(m_mousePosition);
	m_pRollButton->ButtonClick();

	//if button clicked, throw dices
	if(m_pRollButton->ButtonClick())
	{
		throwDices();
	}
}

void Level1Scene::clean()
{
}

void Level1Scene::handleEvents()
{
	int wheel = 0;

	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch(event.button.button)
			{
			case SDL_BUTTON_LEFT:

				m_pRollButton->setMouseButtonClicked(true);
			
				break;
			}
		
			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pRollButton->setMouseButtonClicked(false);
				//Set click register value to 0, to register again
				m_pRollButton->setOnlyRegisterClickOnce(0);

				break;
			}
			break;
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
				break;
			case SDLK_2:
				TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
				break;
			

				/************************************************************************/
			case SDLK_w:
				
				break;
			case SDLK_s:
				
				break;
			case SDLK_a:

				break;
			case SDLK_d:

				break;
			}
			
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				
				break;

			case SDLK_s:
				
				break;

			case SDLK_a:

				break;
			case SDLK_d:

				break;
			}
			
			break;
		default:
			break;
		}
	}
}

void Level1Scene::start()
{
	
	
	m_pRightDiceString = "6";
	m_pLeftDiceString = "6";
	
	//allocate memory for gameobjects
	m_pRollButton = new RollButton();
	m_pRollButton->setMouseButtonClicked(false);
	addChild(m_pRollButton);
	m_pLeftDice = new LeftDice();
	m_pRightDice = new RightDice();
	initializeLabels();
	
}

glm::vec2 Level1Scene::getMousePosition()
{
	return m_mousePosition;
}

void Level1Scene::throwDices()
{
	//check if the button hasn't been clicked even once
	if(m_pRollButton->getOnlyRegisterClickOnce() == 0)
	{
		//generate random numbers
		m_pRandDiceLeft = Util::RandomRange(1, 6);
		m_pRandDiceRight = Util::RandomRange(1, 6);

		//compare the numbers for the dice images
		checkLeftDiceNumber(m_pRandDiceLeft);
		checkRightDiceNumber(m_pRandDiceRight);

		//sum the numbers for total amount
		m_pResultInt = m_pRandDiceLeft + m_pRandDiceRight;

		//change values to string and add in labels
		stringstream leftDiceStream;
		leftDiceStream << m_pRandDiceLeft;
		leftDiceStream >> m_pLeftDiceString;
		m_pLeftDiceLabel->setText(m_pLeftDiceString);

		stringstream rightDiceStream;
		rightDiceStream << m_pRandDiceRight;
		rightDiceStream >> m_pRightDiceString;
		m_pRightDiceLabel->setText(m_pRightDiceString);

		stringstream resultStream;
		resultStream << m_pResultInt;
		resultStream >> m_pResultString;
		m_pResultLabel->setText("Result: " + m_pResultString);
		
		
	}
	//set the button register to 1, so no more cicks registered while the button ís pressed
	m_pRollButton->setOnlyRegisterClickOnce(1);
	
}
//check left dice number
void Level1Scene::checkLeftDiceNumber(int leftDice)
{
	switch(leftDice)
	{
	case Dice1:
		m_leftDiceImage = "Dice1Left";
		break;
	case Dice2:
		m_leftDiceImage = "Dice2Left";
		break;
	case Dice3:
		m_leftDiceImage = "Dice3Left";
		break;
	case Dice4:
		m_leftDiceImage = "Dice4Left";
		break;
	case Dice5:
		m_leftDiceImage = "Dice5Left";
		break;
	case Dice6:
		m_leftDiceImage = "Dice6Left";
			break;

	default:
		break;
	}
}
//check right dice number
void Level1Scene::checkRightDiceNumber(int rightDice)
{
	switch (rightDice)
	{
	case Dice1:
		m_rightDiceImage = "Dice1Right";
		break;
	case Dice2:
		m_rightDiceImage = "Dice2Right";
		break;
	case Dice3:
		m_rightDiceImage = "Dice3Right";
		break;
	case Dice4:
		m_rightDiceImage = "Dice4Right";
		break;
	case Dice5:
		m_rightDiceImage = "Dice5Right";
		break;
	case Dice6:
		m_rightDiceImage = "Dice6Right";
		break;

	default:
		break;
	}
}
//initialize labels
void Level1Scene::initializeLabels()
{
	SDL_Color green = { 0, 255, 50, 255 };

	m_pLeftDiceLabel = new Label(m_pLeftDiceString, "Dock51", 20, green, glm::vec2(m_pLeftDice->getPosition().x, m_pLeftDice->getPosition().y+150.0f));
	m_pLeftDiceLabel->setParent(this);
	addChild(m_pLeftDiceLabel);

	m_pRightDiceLabel = new Label( m_pRightDiceString, "Dock51", 20, green, glm::vec2(m_pRightDice->getPosition().x, m_pRightDice->getPosition().y + 150.0f));
	m_pRightDiceLabel->setParent(this);
	addChild(m_pRightDiceLabel);

	m_pResultLabel = new Label("Result: " + m_pResultString, "Dock51", 20, green, glm::vec2(m_pRightDice->getPosition().x-150, m_pRollButton->getPosition().y - 50.0f));
	m_pRightDiceLabel->setParent(this);
	addChild(m_pRightDiceLabel);

}

