/**************************************************************************************
File Name    : Level8.h
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

class Level8 : public State
{
	friend class Game;

protected:
	Level8() : State()
	{
	}

	~Level8() override {};

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
	Object Box1, Box2, Box3, Box4;
	LevelClear player1Clear, player2Clear;
	Index level8 = Index(6, 10);
    Object levelSign;
    Object Music;
};