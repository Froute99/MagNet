/**************************************************************************************
File Name    : Player1BoxMove.h
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

class Player1BoxMove : public Component
{
public:
    Player1BoxMove() : Component(eComponentTypes::Player1BoxMove) {} // construcor about component
    ~Player1BoxMove() {}

    // Initialize the component info
    virtual void Initialize(void);
    
    // per frame behavior of component
    virtual void Update(float dt);
    
    Character*   Player1;
    Index*       Level;

private:
};