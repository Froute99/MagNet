/**************************************************************************************
File Name    : EndingCutscene.h
Project name : MaG+NeT
Author	     : Eunjin Hong
Email	     : chocob0217@gmail.com
Copyright Information :
    "All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/

#pragma once
#include "engine\State.h"
#include "engine\Object.h"

class EndingCutscene : public State
{
    friend class Game;

protected:
    EndingCutscene() : State() {};
    ~EndingCutscene() override {};

    // Derived initialize function
    void Initialize() override;
    // Derived Update function
    void Update(float dt) override;
    // Derived Close function
    void Close() override;
	int sceneNumber = 0;

private:
    Object cutScene;
    Object pressEnter;
    Object endingSong;
};