/**************************************************************************************
File Name    : LevelClearScreen.h
Project name : MaG+NeT
Author	     : Eunjin Hong
Email	     : chocob0217@gmail.com
Copyright Information :
    "All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/

#pragma once
#include "engine\State.h"
#include "engine\Object.h"

class LevelClearScreen : public State
{
    friend class Game;

protected:
    LevelClearScreen() : State() {};
    ~LevelClearScreen() override {};

    // Derived initialize function
    void Initialize() override;
    // Derived Update function
    void Update(float dt) override;
    // Derived Close function
    void Close() override;

private:
    Object magVictory;
    Object netVictory;
    Object levelClear;
    Object pressN;
    Object clearMusic;
};
