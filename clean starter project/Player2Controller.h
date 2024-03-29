/**************************************************************************************
File Name    : Player2Controller.h
Project name : MaG+NeT
Author	     : Doyoung Lee
Email	     : doyoung413@gmail.com
Copyright Information :
    "All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/

#pragma once
#include "Component.h"
#include "Character.h"

class Index;

class Player2Controller : public Component
{
public:
    Player2Controller();
    ~Player2Controller();
    
    // Initialize the component info
    virtual void    Initialize(void);
    
    // per frame behavior of component
    virtual void    Update(float dt);
    
    Character* Player2;
    Object* Box;
	std::vector<Object*> Boxes;
    Index* Level;

private:
    SDL_Scancode input;
    float movementAmount = 0;
};