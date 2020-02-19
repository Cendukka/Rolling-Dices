#include "Rollbutton.h"
#include "Game.h"

RollButton::RollButton()

	:Button(
		"../Assets/textures/rollButton.png",
		"Rollbutton",
		ROLL_BUTTON, glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.85f)), m_isClicked(false)
	
{
}

RollButton::~RollButton()
{
}

int RollButton::getOnlyRegisterClickOnce()
{
	return m_pClickFlag;
}

void RollButton::setOnlyRegisterClickOnce(int clickFlag)
{
	m_pClickFlag = clickFlag;
}

bool RollButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			m_isClicked = true;
		}
		return true;
	}


	return false;
}
