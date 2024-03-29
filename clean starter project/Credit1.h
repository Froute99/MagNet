/**************************************************************************************
File Name    : Credit1.h
Project name : MaG+NeT
Author	     : Eunjin Hong
Email	     : chocob0217@gmail.com
Copyright Information :
    "All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/

#pragma once
#include "engine\State.h"
#include "engine\Object.h"

class Credit1 : public State
{
    friend class Game;

protected:
    Credit1() : State() {};
    ~Credit1() override {};

    // Derived initialize function
    void Initialize() override;
    // Derived Update function
    void Update(float dt) override;
    // Derived Close function
    void Close() override;

private:
    Object credit1;
    Object pressBack;
    Object pressSpace;
};
