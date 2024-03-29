/**************************************************************************************
File Name    : LevelChangeCommand.h
Project name : MaG+NeT
Author	     : Jihoon Kim
Email	     : jihoon1602@gmail.com
Copyright Information :
    "All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/

#pragma once
#include "Command.h"

class LevelChangeCommand : public Command
{
public:
	LevelChangeCommand();
	~LevelChangeCommand();
	virtual void Execute() override;
public:
};
