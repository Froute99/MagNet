/**************************************************************************************
File Name    : Player1BoxMove.cpp
Project name : MaG+NeT
Author	     : Doyoung Lee
Email	     : doyoung413@gmail.com
Copyright Information :
    "All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/

#include "Player1BoxMove.h"
#include "Character.h"
#include <engine/State.h>

void Player1BoxMove::Initialize()
{
}

void Player1BoxMove::Update(float /*dt*/)
{
    if (State::m_input->IsTriggered(SDL_SCANCODE_LSHIFT)) //prevent for bug(press button while box moving)
    {
        if (Player1->GetCharacterPressable() == Character::PlayerPressableStatus::can)
        {
            Character::BoxMovableStatus movableStatus = Player1->GetMovableStatus();
            Player1->SetMovableStatus(static_cast<Character::BoxMovableStatus>(-movableStatus)); //change movable state
            Player1->SetPlayer1SpriteStop(*Player1, *Level); //change sprite
        }
    }
}