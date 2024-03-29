/**************************************************************************************
File Name    : Level6.h
Project name : MaG+NeT
Author	     : Eunjin Hong
Email	     : chocob0217@gmail.com
Copyright Information :
    "All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/#pragma once
#include "engine\State.h"
#include "engine\Object.h"
#include "Character.h"
#include "Index.hpp"
#include "LevelClear.hpp"

class Level6 : public State
{
    friend class Game;
protected:

    Level6() : State()
    {
    }

    ~Level6() override {};

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
    Index level6 = Index(7, 12);
    Object levelSign;
    Object Music;
};