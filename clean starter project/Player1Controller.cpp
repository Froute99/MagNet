/**************************************************************************************
File Name    : Player1Controller.cpp
Project name : MaG+NeT
Author	     : Doyoung Lee
Email	     : doyoung413@gmail.com
Copyright Information :
    "All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/

#include "Player1Controller.h"
#include "Character.h"
#include <engine/State.h>

Player1Controller::Player1Controller()
    : Component(eComponentTypes::Player1Controller)
{
}

Player1Controller::~Player1Controller(){}

void Player1Controller::Initialize(){}

void Player1Controller::Update(float /*dt*/)
{
    if (Player1->GetCharacterPressable() == Character::PlayerPressableStatus::can) //check player can press button
    {
        if (State::m_input->IsPressed(SDL_SCANCODE_A))
        {
            input = SDL_SCANCODE_A; //get input button value
            for (size_t i = 0; i < Boxes.size(); ++i)
            {
                Player1->SetBoxId(i); //set box's id for functions which related to box
                Player1->BoxMove(input, *Level, *Player1, *Boxes[i]); //move the box
            }
            Player1->MovePlayer(input, *Level); //move the player
        }

        else if (State::m_input->IsPressed(SDL_SCANCODE_D))
        {
            input = SDL_SCANCODE_D;
            for (size_t i = 0; i < Boxes.size(); ++i)
            {
                Player1->SetBoxId(i);
                Player1->BoxMove(input, *Level, *Player1, *Boxes[i]);
            }
            Player1->MovePlayer(input, *Level);
        }

        else if (State::m_input->IsPressed(SDL_SCANCODE_W))
        {
            input = SDL_SCANCODE_W;
            for (size_t i = 0; i < Boxes.size(); ++i)
            {
                Player1->SetBoxId(i);
                Player1->BoxMove(input, *Level, *Player1, *Boxes[i]);
            }
            Player1->MovePlayer(input, *Level);
        }

        else if (State::m_input->IsPressed(SDL_SCANCODE_S))
        {
            input = SDL_SCANCODE_S;
            for (size_t i = 0; i < Boxes.size(); ++i)
            {
                Player1->SetBoxId(i);
                Player1->BoxMove(input, *Level, *Player1, *Boxes[i]);
            }
            Player1->MovePlayer(input, *Level);
        }
    }


    else if (Player1->GetCharacterPressable() == Character::PlayerPressableStatus::cannot) //check player cannot press button
    {
        if (movementAmount < GRID_SCALE) //check movementAmount is lower than grid
        {
            Player1->BoxMovement(input, *Player1, *Boxes[Player1->GetBoxId()]);
            Player1->PlayerMovement(input, *Player1);
            movementAmount += MOVEMENT; //increase movementAmount
        }//linear interpolation

        else if (movementAmount == GRID_SCALE) //check movementAmount is same as grid
        {
            Player1->SetPlayer1SpriteStop(*Player1, *Level);
            Player1->SetCharacterPressable(Character::PlayerPressableStatus::can);
            
            if (Player1->GetBoxCanMove() == Character::BoxCanMove::Moveable)
            {
                Player1->SetBoxCanMove(Character::BoxCanMove::Unmoveable);
            }
            movementAmount = 0; //stop linear interpolation
        }
    }
}
