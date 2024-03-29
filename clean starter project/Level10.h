/**************************************************************************************
File Name    : Level10.h
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

class Level10 : public State
{
    friend class Game;

protected:
    Level10() : State()
    {
    }

    ~Level10() override {}

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
    Object Box1, Box2, Box3, Box4, Box5;
    LevelClear player1Clear, player2Clear;
    Index level10 = Index(11, 9);
    Object levelSign;
    Object Music;
};