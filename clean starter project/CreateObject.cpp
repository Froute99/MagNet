/**************************************************************************************
File Name    : CreateObject.cpp
Project name : MaG+NeT
Author	     : Doyoung Lee
Email	     : doyoung413@gmail.com
Copyright Information :
    "All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/

#include "CommonLevel.h"
#include "CreateObject.h"
const float SCALE_X = 48.f;
const float SCALE_Y = 48.f;

namespace Color
{
    constexpr SDL_Color BLACK = { 0, 0, 0, 255 };
    constexpr SDL_Color WHITE = { 255, 255, 255, 255 };
    constexpr SDL_Color RED = { 255, 0, 0, 255 };
    constexpr SDL_Color GREEN = { 34, 140, 67, 255 };
    constexpr SDL_Color BLUE = { 0, 0, 255, 255 };
    constexpr SDL_Color GREY = { 136, 136, 136, 255 };
    constexpr SDL_Color WALLGREY = { 127, 125, 103, 255 };
    constexpr SDL_Color CORAL_RED = { 255, 68, 68, 255 };
    constexpr SDL_Color BROWN = { 134, 102, 74, 255 };
    constexpr SDL_Color SKY = { 135, 192, 235, 255 };
    const SDL_Color WALL_COLOR = { 50, 50, 50, 200 };
    const SDL_Color BOX_COLOR = { 200, 200, 200, 180 };
}

Object& MakeObject(Object& object, const char* name, float xPos, float yPos)
{
    const float POSITION_Z = 0.f;

    object.SetName(name);
    object.transform.position.Set(xPos * SCALE_X, yPos * SCALE_Y, POSITION_Z);
    object.transform.SetScale(SCALE_X, SCALE_Y);
    object.sprite.LoadImage("texture/rect.png", State::m_renderer);
    object.physics.bodyType = Physics::STATIC;
    State::sCurrentState->AddObject(&object);

    return object;
} //make object such as player, clear tile

void CreateWall(float xPos, float yPos)
{
    const float POSITION_Z = 0.f;

    Wall *newWall = new Wall;
 
    newWall->transform.position.Set(xPos * SCALE_X, yPos * SCALE_Y, POSITION_Z);
    newWall->transform.SetScale(SCALE_X, SCALE_Y);
    newWall->sprite.LoadImage("texture/Wall.png", State::m_renderer);

    State::sCurrentState->AddDynamicObjectAndInitialize(newWall);
}// make wall dynamically 

void CreateTile(float xPos, float yPos)
{
    const float POSITION_Z = -32.f;

    Tile *newTile = new Tile;
    newTile->transform.position.Set(xPos * SCALE_X, yPos * SCALE_Y, POSITION_Z);
    newTile->transform.SetScale(SCALE_X, SCALE_Y);
    newTile->sprite.LoadImage("texture/Tile.png", State::m_renderer);

    State::sCurrentState->AddDynamicObjectAndInitialize(newTile);
}// make wall dynamically 