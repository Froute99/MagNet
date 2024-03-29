/**************************************************************************************
File Name    : Player2BoxMove.cpp
Project name : MaG+NeT
Author	     : Doyoung Lee
Email	     : doyoung413@gmail.com
Copyright Information :
    "All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/

#include "Player2BoxMove.h"
#include "Character.h"
#include <engine/State.h>

void Player2BoxMove::Initialize()
{
}

void Player2BoxMove::Update(float /*dt*/)
{
    if (State::m_input->IsTriggered(SDL_SCANCODE_RSHIFT)) //prevent for bug(press button while box moving)
    {
        if (Player2->GetCharacterPressable() == Character::PlayerPressableStatus::can)
        {
            Character::BoxMovableStatus movableStatus = Player2->GetMovableStatus();
            Player2->SetMovableStatus(static_cast<Character::BoxMovableStatus>(-movableStatus)); //change movable state
            Player2->SetPlayer2SpriteStop(*Player2, *Level); //change sprite
        }
    }
}