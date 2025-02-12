/**************************************************************************************
File Name    : Level1.h
Project name : MaG+NeT
Author	     : Junghak Kim
Email	     : dbh99619@gmail.com
Copyright Information :
    "All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/

#pragma once
#include "engine\State.h"
#include "engine\Object.h"
#include "Character.h"
#include "Index.hpp"
#include "LevelClear.hpp"

class Level1 : public State
{
	friend class Game;

protected:
	Level1() : State()
	{
	}

	~Level1() override {};

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
	Object Box1, Box2;
    LevelClear player1Clear, player2Clear;
    Index level1 = Index(10, 8);
    Object levelSign;
    Object Music;
};