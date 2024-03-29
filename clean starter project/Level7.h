/**************************************************************************************
File Name    : Level7.h
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

class Level7 : public State
{
    friend class Game;
protected:

    Level7() : State()
    {
    }

    ~Level7() override {};

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
    Object Box1, Box2, Box3, Box4, Box5, Box6, Box7, Box8;
    LevelClear player1Clear, player2Clear;
    Index level7 = Index(7, 8);
    Object levelSign;
    Object Music;
};