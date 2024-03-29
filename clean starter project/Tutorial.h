/**************************************************************************************
File Name    : Tutorial.h
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

class Tutorial : public State
{
    friend class Game;

protected:
    Tutorial() : State()
    {
    }

    ~Tutorial() override {}

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
    LevelClear player1Clear, player2Clear;
    Index tutorial = Index(10, 10);
    Object Box1, Box2, Box3, Box4, Box5, Box6, Box7, Box8;
    Object introTexts[3];
    Object magTuto;
    Object netTuto;
    Object resetTuto;
    Object levelSign;
    Object Music;
};