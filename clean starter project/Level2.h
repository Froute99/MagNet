/**************************************************************************************
File Name    : Level2.h
Project name : MaG+NeT
Author	     : Eunjin Hong
Email	     : chocob0217@gmail.com
Copyright Information :
    "All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/

#pragma once
#include "engine\State.h"
#include "engine\Object.h"
#include "Character.h"
#include "Index.hpp"
#include "LevelClear.hpp"

class Level2 : public State
{
    friend class Game;
    
protected:
    Level2() : State()
    {
    }

    ~Level2() override {};

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
    Index level2 = Index(6, 11);
    Object levelSign;
    Object Music;
};