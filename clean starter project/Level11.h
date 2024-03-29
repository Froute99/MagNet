/**************************************************************************************
File Name    : Level11.h
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

class Level11 : public State
{
	friend class Game;

protected:
	Level11() : State()
	{
	}

	~Level11() override {};

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
	Object Box1, Box2, Box3, Box4, Box5, Box6, Box7, Box8, Box9, Box10, Box11, Box12, Box13, Box14, Box15, Box16;
	LevelClear player1Clear, player2Clear;
    Index level11 = Index(7, 11);
    Object levelSign;
    Object Music;
};