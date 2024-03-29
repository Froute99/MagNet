/**************************************************************************************
File Name        : Character.h
Project name     : MaG+NeT
Primary Author   : Junghak Kim
Secondary Author : Doyoung Lee
Email	         : dbh99619@gmail.com
Copyright Information :
    "All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/

#pragma once
#include <engine/Object.h>

#define GRID_SCALE  48.f 
#define  MOVEMENT  4.f
#define ANIMATION_SPEED 8.f

class Index;

class Character : public Object
{
public:
    enum Direction { Left = 0, Up, Right, Down }; //direction
    enum BoxMovableStatus { Unable = -1, Enable = 1 }; //state that player can move the box
    enum PlayerPressableStatus { cannot = 0, can = 1 }; //state that player can press the botton
    enum BoxCanMove { Unmoveable = -1, Moveable = 1 }; //state that box is moving
    void MovePlayer(SDL_Scancode input, Index& level);
    void BoxMove(SDL_Scancode input, Index& index, Character& player, Object& box);
	Direction GetDirection() const { return playerDirection; }
   void SetDirection(Direction direction) { playerDirection = direction; }
    int GetCharacterXIndex() const { return xIndex; }
    void SetCharacterXIndex(int newX) { xIndex = newX; }
    int GetCharacterYIndex() const { return yIndex; }
    void SetCharacterYIndex(int newY) { yIndex = newY; }
 
    BoxMovableStatus GetMovableStatus() const { return isBoxMovable; }
    void SetMovableStatus(BoxMovableStatus value) { isBoxMovable = value; }
    PlayerPressableStatus GetCharacterPressable() const { return isPlayerPressable; }
    void SetCharacterPressable(PlayerPressableStatus value) { isPlayerPressable = value; }
    void PlayerMovement(SDL_Scancode input, Character& player);
    void BoxMovement(SDL_Scancode input, Character& player, Object& Box);
    size_t GetBoxId() const { return boxId; }
    void SetBoxId(size_t value) { boxId_ = value; };
    BoxCanMove GetBoxCanMove() const { return isBoxCanMove; }
    void SetBoxCanMove(BoxCanMove value) { isBoxCanMove = value; }
    void SetPlayer1SpriteStop(Character& player, Index& index);
    void SetPlayer1SpriteMove(SDL_Scancode input, Index& index, Character& player);
    void SetPlayer2SpriteStop(Character& player, Index& index);
    void SetPlayer2SpriteMove(SDL_Scancode input, Index& index, Character& player);
private:
    BoxMovableStatus isBoxMovable = Unable;
    Direction playerDirection = Down;
    PlayerPressableStatus isPlayerPressable = can;
    BoxCanMove isBoxCanMove = Unmoveable;
    int xIndex = 0, yIndex = 0;
    size_t boxId;
    size_t boxId_;

    Object boxMoveSound;
};