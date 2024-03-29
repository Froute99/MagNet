/**************************************************************************************
File Name    : LevelChangeCommand.cpp
Project name : MaG+NeT
Author	     : Jihoon Kim
Email	     : jihoon1602@gmail.com
Copyright Information :
    "All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/

#include "LevelChangeCommand.h"
#include "engine/State.h"
#include "CommonLevel.h"

LevelChangeCommand::LevelChangeCommand() :
	Command(eCommandTypes::LevelChangeCommand)
{
}

LevelChangeCommand::~LevelChangeCommand()
{
}

void LevelChangeCommand::Execute()
{
    State::sCurrentState->m_game->Change(LV_Level1);
    State::m_game->Change(LV_Level1);
}
