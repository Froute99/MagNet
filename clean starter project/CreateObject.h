/**************************************************************************************
File Name    : CreateObject.h
Project name : MaG+NeT
Author	     : Doyoung Lee
Email	     : doyoung413@gmail.com
Copyright Information :
    "All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/

#pragma once
#include "engine\Object.h"
#include <list>

class Wall : public Object
{
    unsigned wallCreatedCount;
    std::list<Wall*> wallList;
}; //class about wall for make object dynamically

class Tile : public Object
{
    unsigned tileCreatedCount;
    std::list<Tile*> tileList;
}; //class about tile for make object dynamically

Object& MakeObject(Object& object, const char* name, float xPos, float yPos);

void CreateWall(float xPos, float yPos);

void CreateTile(float xPos, float yPos);
