/******************************************************************************/
/*!
\file   LevelTest.h
\author Doyoung Lee and Jeonghak Kim
\par    email: , dbh99619@gmail.com
\ver	Prototype
\date   2019/04/13

LevelTest for prototype
*/
/******************************************************************************/
#pragma once
#include "engine\State.h"
#include "engine\Object.h"
#include "Character.h"
#include "Index.h"
#include "LevelClear.h"

class LevelTest : public State
{
	friend class Game;
protected:

	LevelTest() : State()
	{
	}

	~LevelTest() override {};

	// Derived initialize function
	void Initialize() override;
	// Derived Update function
	void Update(float dt) override;
	// Derived Close function
	void Close() override;

private:

	std::vector<Object*> m_dynamicList;

	void SetIntroTexts();
	// Objects
	Character Player1, Player2;
	Object Box1, Box2;
	Object introTexts[3];

	LevelClear player1Clear, player2Clear;
	Index levelTest = Index(8, 10);

	Object levelSign;
	Object Music;
};
