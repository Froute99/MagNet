/**************************************************************************************
File Name    : Player2BoxMove.h
Project name : MaG+NeT
Author	     : Doyoung Lee
Email	     : doyoung413@gmail.com
Copyright Information :
    "All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/

#pragma once
#include "Character.h"
#include "Component.h"

class Index;

class Player2BoxMove : public Component
{
public:
    Player2BoxMove() : Component(eComponentTypes::Player2BoxMove) {} // construcor about component
    ~Player2BoxMove() {}

    // Initialize the component info
    virtual void Initialize(void);
    
    // per frame behavior of component
    virtual void Update(float dt);
    
    Character*   Player2;
    Index*       Level;

private:
};