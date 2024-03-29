/**************************************************************************************
File Name    : Level3.h
Project name : MaG+NeT
Author	     : Jihoon Kim
Email	     : jihoon1602@gmail.com
Copyright Information :
    "All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/

#pragma once
#include "engine\State.h"
#include "engine\Object.h"
#include "Character.h"
#include "Index.hpp"
#include "LevelClear.hpp"

class Level3 : public State
{
	friend class Game;
protected:

	Level3() : State()
	{
	}

	~Level3() override {};

	// Derived initialize function
	void Initialize() override;
	// Derived Update function
	void Update(float dt) override;
	// Derived Close function
	void Close() override;

private:

	std::vector<Object*> m_dynamicList;

	// Objects
	Character Player1, Player2;
	Object Box1, Box2, Box3;
    LevelClear player1Clear, player2Clear;
	Index level3 = Index(5, 8);
    Object levelSign;
    Object Music;
};