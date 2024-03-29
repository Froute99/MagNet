/**************************************************************************************
File Name    : Player2Controller.cpp
Project name : MaG+NeT
Author	     : Doyoung Lee
Email	     : doyoung413@gmail.com
Copyright Information :
    "All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/

#include "Character.h"
#include "Player2Controller.h"
#include <engine/State.h>

Player2Controller::Player2Controller()
    : Component(eComponentTypes::Player2Controller)
{
}

Player2Controller::~Player2Controller() {}

void Player2Controller::Initialize() {}

void Player2Controller::Update(float /*dt*/)
{
    if (Player2->GetCharacterPressable() == Character::PlayerPressableStatus::can) //check player can press button
    {
        if (State::m_input->IsPressed(SDL_SCANCODE_LEFT)) //get input button value
        {
            input = SDL_SCANCODE_LEFT;
            for (size_t i = 0; i < Boxes.size(); ++i)
            {
                Player2->SetBoxId(i); //set box's id for functions which related to box
                Player2->BoxMove(input, *Level, *Player2, *Boxes[i]); //move the box
            }
            Player2->MovePlayer(input, *Level); //move the player
        }

        else if (State::m_input->IsPressed(SDL_SCANCODE_RIGHT))
        {
            input = SDL_SCANCODE_RIGHT;
            for (size_t i = 0; i < Boxes.size(); ++i)
            {
                Player2->SetBoxId(i);
                Player2->BoxMove(input, *Level, *Player2, *Boxes[i]);
            }
            Player2->MovePlayer(input, *Level);
        }

        else if (State::m_input->IsPressed(SDL_SCANCODE_UP))
        {
            input = SDL_SCANCODE_UP;
            for (size_t i = 0; i < Boxes.size(); ++i)
            {
                Player2->SetBoxId(i);
                Player2->BoxMove(input, *Level, *Player2, *Boxes[i]);
            }
            Player2->MovePlayer(input, *Level);
        }

        else if (State::m_input->IsPressed(SDL_SCANCODE_DOWN))
        {
            input = SDL_SCANCODE_DOWN;
            for (size_t i = 0; i < Boxes.size(); ++i)
            {
                Player2->SetBoxId(i);
                Player2->BoxMove(input, *Level, *Player2, *Boxes[i]);
            }
            Player2->MovePlayer(input, *Level);
        }
    }


    else if (Player2->GetCharacterPressable() == Character::PlayerPressableStatus::cannot) //check player cannot press button
    {
        if (movementAmount < GRID_SCALE) //check movementAmount is lower than grid
        {
            Player2->BoxMovement(input, *Player2, *Boxes[Player2->GetBoxId()]);
            Player2->PlayerMovement(input, *Player2);
            movementAmount += MOVEMENT; //increase movementAmount
        }

        else if (movementAmount == GRID_SCALE) //check movementAmount is same as grid
        {
            Player2->SetPlayer2SpriteStop(*Player2, *Level);
            Player2->SetCharacterPressable(Character::PlayerPressableStatus::can);
            
            if (Player2->GetBoxCanMove() == Character::BoxCanMove::Moveable)
            {
                Player2->SetBoxCanMove(Character::BoxCanMove::Unmoveable);
            }
            movementAmount = 0; //stop linear interpolation
        }
    }
}
