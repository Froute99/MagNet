/**************************************************************************************
File Name    : RegisterComponents.cpp
Project name : MaG+NeT
Author	     : Doyoung Lee
Email	     : doyoung413@gmail.com
Copyright Information :
    "All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/

#include "RegisterComponents.h"
#include "DemoUIButton.h"
#include "engine/ComponentBuilder.h"
#include "engine\State.h"
#include "Player1Controller.h"
#include "Player2Controller.h"
#include "Player1BoxMove.h"
#include "Player2BoxMove.h"

/**
 * \brief
 * Register each component builder
 */
void RegisterComponents()
{
    State::AddComponentBuilder(eComponentTypes::DemoUIButton, new ComponentTBuilder<DemoUIButton>());
    State::AddComponentBuilder(eComponentTypes::Player1Controller, new ComponentTBuilder<Player1Controller>());
    State::AddComponentBuilder(eComponentTypes::Player2Controller, new ComponentTBuilder<Player2Controller>());
    State::AddComponentBuilder(eComponentTypes::Player1BoxMove, new ComponentTBuilder<Player1BoxMove>());
    State::AddComponentBuilder(eComponentTypes::Player2BoxMove, new ComponentTBuilder<Player2BoxMove>());
}

void UnregisterComponents()
{
    State::RemoveComponentBuilder(eComponentTypes::DemoUIButton);
    State::RemoveComponentBuilder(eComponentTypes::Player1Controller);
    State::RemoveComponentBuilder(eComponentTypes::Player2Controller);
    State::RemoveComponentBuilder(eComponentTypes::Player1BoxMove);
    State::RemoveComponentBuilder(eComponentTypes::Player2BoxMove);
}
