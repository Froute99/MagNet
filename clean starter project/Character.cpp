/**************************************************************************************
File Name        : Character.cpp
Project name     : MaG+NeT
Primary Author   : Junghak Kim
Secondary Author : Doyoung Lee
Email	         : dbh99619@gmail.com
Copyright Information :
    "All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/

#include "Character.h"
#include "CommonLevel.h"
#include "Index.hpp"

b2Vec2 GetIndexByBox(Object* box)		// helper function Box 
{
	return { box->transform.position.x / GRID_SCALE, box->transform.position.y / GRID_SCALE };
}


void Character::MovePlayer(SDL_Scancode input, Index& level) //function about player move
{
	switch (input)
	{
	case SDL_SCANCODE_A: //player1
		if (!level.IsObject(GetCharacterXIndex() - 1, GetCharacterYIndex())) //check player can move
		{
			this->SetCharacterPressable(cannot); //change state player cannot press button
			if ((level.GetIndex(xIndex, yIndex) == Index::LEVEL_COMPONENT::BOX) && (this->isBoxMovable == Enable)) //check player moving the box
			{
				SetPlayer1SpriteMove(input, level, *this); //change sprite
				SetDirection(Character::Right); //set direction
				SetCharacterXIndex(GetCharacterXIndex() - 1); //change player's location
				level.SetIndex(xIndex, yIndex, Index::MAG); //change player's position
			}
			else if (level.GetIndex(xIndex, yIndex) != Index::LEVEL_COMPONENT::BOX)  //check player not moving the box
			{
				SetPlayer1SpriteMove(input, level, *this); //change sprite
				SetDirection(Character::Left); //set direction
				level.SetIndex(xIndex, yIndex, Index::EMPTY);
				SetCharacterXIndex(GetCharacterXIndex() - 1); //change player's location
				level.SetIndex(xIndex, yIndex, Index::MAG); //change player's position
			}
		}
		else
		{
			SetDirection(Character::Left);
			SetPlayer1SpriteStop(*this, level);
		}
		break;

	case SDL_SCANCODE_D:
		if (!level.IsObject(GetCharacterXIndex() + 1, GetCharacterYIndex()))
		{
			this->SetCharacterPressable(cannot);
			if ((level.GetIndex(xIndex, yIndex) == Index::LEVEL_COMPONENT::BOX) && (this->isBoxMovable == Enable))
			{
				SetPlayer1SpriteMove(input, level, *this);
				SetDirection(Character::Left);
				SetCharacterXIndex(GetCharacterXIndex() + 1);
				level.SetIndex(xIndex, yIndex, Index::MAG);
			}
			else if (level.GetIndex(xIndex, yIndex) != Index::LEVEL_COMPONENT::BOX)
			{
				SetPlayer1SpriteMove(input, level, *this);
				SetDirection(Character::Right);
				level.SetIndex(xIndex, yIndex, Index::EMPTY);
				SetCharacterXIndex(GetCharacterXIndex() + 1);
				level.SetIndex(xIndex, yIndex, Index::MAG);
			}
		}
		else
		{
			SetDirection(Character::Right);
			SetPlayer1SpriteStop(*this, level);
		}
		break;

	case SDL_SCANCODE_W:
		if (!level.IsObject(GetCharacterXIndex(), GetCharacterYIndex() + 1))
		{
			this->SetCharacterPressable(cannot);
			if ((level.GetIndex(xIndex, yIndex) == Index::LEVEL_COMPONENT::BOX) && (this->isBoxMovable == Enable))
			{
				SetPlayer1SpriteMove(input, level, *this);
				SetDirection(Character::Down);
				SetCharacterYIndex(GetCharacterYIndex() + 1);
				level.SetIndex(xIndex, yIndex, Index::MAG);
			}
			else if (level.GetIndex(xIndex, yIndex) != Index::LEVEL_COMPONENT::BOX)
			{
				SetPlayer1SpriteMove(input, level, *this);
				SetDirection(Character::Up);
				level.SetIndex(xIndex, yIndex, Index::EMPTY);
				SetCharacterYIndex(GetCharacterYIndex() + 1);
				level.SetIndex(xIndex, yIndex, Index::MAG);
			}
		}
		else
		{
			SetDirection(Character::Up);
			SetPlayer1SpriteStop(*this, level);
		}
		break;

	case SDL_SCANCODE_S:
		if (!level.IsObject(GetCharacterXIndex(), GetCharacterYIndex() - 1))
		{
			this->SetCharacterPressable(cannot);
			if ((level.GetIndex(xIndex, yIndex) == Index::LEVEL_COMPONENT::BOX) && (this->isBoxMovable == Enable))
			{
				SetPlayer1SpriteMove(input, level, *this);
				SetDirection(Character::Up);
				SetCharacterYIndex(GetCharacterYIndex() - 1);
				level.SetIndex(xIndex, yIndex, Index::MAG);
			}
			else if (level.GetIndex(xIndex, yIndex) != Index::LEVEL_COMPONENT::BOX)
			{
				SetPlayer1SpriteMove(input, level, *this);
				SetDirection(Character::Down);
				level.SetIndex(xIndex, yIndex, Index::EMPTY);
				SetCharacterYIndex(GetCharacterYIndex() - 1);
				level.SetIndex(xIndex, yIndex, Index::MAG);
			}
		}
		else
		{
			SetDirection(Character::Down);
			SetPlayer1SpriteStop(*this, level);
		}
		break;

	case SDL_SCANCODE_LEFT: //player2
		if (!level.IsObject(GetCharacterXIndex() - 1, GetCharacterYIndex())) //check player can move
		{
			this->SetCharacterPressable(cannot); //change state player cannot press button
			SetDirection(Character::Left); //set direction
			if ((level.GetIndex(xIndex - 2, yIndex) == Index::LEVEL_COMPONENT::BOX) && (this->isBoxMovable == Enable)) //check player moving the box
			{
				SetPlayer2SpriteMove(input, level, *this); //change sprite
			}
			else if (level.GetIndex(xIndex - 2, yIndex) != Index::LEVEL_COMPONENT::BOX) //check player not moving the box
			{
				SetPlayer2SpriteMove(input, level, *this); //change sprite
			}
			else
			{
				SetPlayer2SpriteMove(input, level, *this);
			}
			level.SetIndex(xIndex, yIndex, Index::EMPTY);
			SetCharacterXIndex(GetCharacterXIndex() - 1);
			level.SetIndex(xIndex, yIndex, Index::NET); //change player's location & position
		}
		else
		{
			SetDirection(Character::Left);
			SetPlayer2SpriteStop(*this, level);
		}
		break;

	case SDL_SCANCODE_RIGHT:
		if (!level.IsObject(GetCharacterXIndex() + 1, GetCharacterYIndex()))
		{
			this->SetCharacterPressable(cannot);
			SetDirection(Character::Right);
			if ((level.GetIndex(xIndex + 2, yIndex) == Index::LEVEL_COMPONENT::BOX) && (this->isBoxMovable == Enable))
			{
				SetPlayer2SpriteMove(input, level, *this);
			}
			else if (level.GetIndex(xIndex + 2, yIndex) != Index::LEVEL_COMPONENT::BOX)
			{
				SetPlayer2SpriteMove(input, level, *this);
			}
			else
			{
				SetPlayer2SpriteMove(input, level, *this);
			}
			level.SetIndex(xIndex, yIndex, Index::EMPTY);
			SetCharacterXIndex(GetCharacterXIndex() + 1);
			level.SetIndex(xIndex, yIndex, Index::NET);
		}
		else
		{
			SetDirection(Character::Right);
			SetPlayer2SpriteStop(*this, level);
		}
		break;

	case SDL_SCANCODE_UP:
		if (!level.IsObject(GetCharacterXIndex(), GetCharacterYIndex() + 1))
		{
			this->SetCharacterPressable(cannot);
			SetDirection(Character::Up);
			if ((level.GetIndex(xIndex, yIndex + 2) == Index::LEVEL_COMPONENT::BOX) && (this->isBoxMovable == Enable))
			{
				SetPlayer2SpriteMove(input, level, *this);
			}
			else if ((level.GetIndex(xIndex, yIndex + 2) != Index::LEVEL_COMPONENT::BOX))
			{
				SetPlayer2SpriteMove(input, level, *this);
			}
			else
			{
				SetPlayer2SpriteMove(input, level, *this);
			}
			level.SetIndex(xIndex, yIndex, Index::EMPTY);
			SetCharacterYIndex(GetCharacterYIndex() + 1);
			level.SetIndex(xIndex, yIndex, Index::NET);
		}
		else
		{
			SetDirection(Character::Up);
			SetPlayer2SpriteStop(*this, level);
		}
		break;

	case SDL_SCANCODE_DOWN:
		if (!level.IsObject(GetCharacterXIndex(), GetCharacterYIndex() - 1))
		{
			this->SetCharacterPressable(cannot);
			SetDirection(Character::Down);
			if ((level.GetIndex(xIndex, yIndex - 2) == Index::LEVEL_COMPONENT::BOX) && (this->isBoxMovable == Enable))
			{
				SetPlayer2SpriteMove(input, level, *this);
			}
			else if ((level.GetIndex(xIndex, yIndex - 2) != Index::LEVEL_COMPONENT::BOX))
			{
				SetPlayer2SpriteMove(input, level, *this);
			}
			else
			{
				SetPlayer2SpriteMove(input, level, *this);
			}
			level.SetIndex(xIndex, yIndex, Index::EMPTY);
			SetCharacterYIndex(GetCharacterYIndex() - 1);
			level.SetIndex(xIndex, yIndex, Index::NET);
		}
		else
		{
			SetDirection(Character::Down);
			SetPlayer2SpriteStop(*this, level);
		}
		break;
	default:;
	}
}


void Character::BoxMove(SDL_Scancode input, Index& index, Character& player, Object& box) //function about player move the box
{
	if (player.isBoxMovable == Enable) //check player can move the box
	{
		if (player.isBoxCanMove == Unmoveable) //check box state is moving
		{
			switch (input)
			{
			case SDL_SCANCODE_A: //player1
				if ((index.GetIndex(xIndex + 1, yIndex) == Index::LEVEL_COMPONENT::BOX) &&
					(b2Vec2(static_cast<float>(xIndex + 1.f), static_cast<float>(yIndex)) == GetIndexByBox(&box))) //check box is in front of the box
				{
					if (!index.IsObject(GetCharacterXIndex() - 1, GetCharacterYIndex())) //check box can move
					{
						boxMoveSound.SetName("boxSlide");
						boxMoveSound.sound.LoadSound("sound/SlideBox.wav");
						boxMoveSound.sound.SetVolume(100);
						boxMoveSound.sound.Play(); // soundeffect
						player.isBoxCanMove = Moveable; //box state is moving
						index.SetIndex(xIndex, yIndex, Index::BOX);
						index.SetIndex(xIndex + 1, yIndex, Index::EMPTY); //set box location
						boxId = boxId_; //set box id
					}
				}
				break;

			case SDL_SCANCODE_D:
				if ((index.GetIndex(xIndex - 1, yIndex) == Index::LEVEL_COMPONENT::BOX) &&
					(b2Vec2(static_cast<float>(xIndex - 1.f), static_cast<float>(yIndex)) == GetIndexByBox(&box)))
				{
					if (!index.IsObject(GetCharacterXIndex() + 1, GetCharacterYIndex()))
					{
						boxMoveSound.SetName("boxSlide");
						boxMoveSound.sound.LoadSound("sound/SlideBox.wav");
						boxMoveSound.sound.SetVolume(100);
						boxMoveSound.sound.Play();
						player.isBoxCanMove = Moveable;
						index.SetIndex(xIndex, yIndex, Index::BOX);
						index.SetIndex(xIndex - 1, yIndex, Index::EMPTY);;
						boxId = boxId_;
					}
				}
				break;

			case SDL_SCANCODE_W:
				if ((index.GetIndex(xIndex, yIndex - 1) == Index::LEVEL_COMPONENT::BOX) &&
					(b2Vec2(static_cast<float>(xIndex), static_cast<float>(yIndex - 1.f)) == GetIndexByBox(&box)))
				{
					if (!index.IsObject(GetCharacterXIndex(), GetCharacterYIndex() + 1))
					{
						boxMoveSound.SetName("boxSlide");
						boxMoveSound.sound.LoadSound("sound/SlideBox.wav");
						boxMoveSound.sound.SetVolume(100);
						boxMoveSound.sound.Play();
						player.isBoxCanMove = Moveable;
						index.SetIndex(xIndex, yIndex, Index::BOX);
						index.SetIndex(xIndex, yIndex - 1, Index::EMPTY);
						boxId = boxId_;
					}
				}
				break;

			case SDL_SCANCODE_S:
				if ((index.GetIndex(xIndex, yIndex + 1) == Index::LEVEL_COMPONENT::BOX) &&
					(b2Vec2(static_cast<float>(xIndex), static_cast<float>(yIndex + 1.f)) == GetIndexByBox(&box)))
				{
					if (!index.IsObject(GetCharacterXIndex(), GetCharacterYIndex() - 1))
					{
						boxMoveSound.SetName("boxSlide");
						boxMoveSound.sound.LoadSound("sound/SlideBox.wav");
						boxMoveSound.sound.SetVolume(100);
						boxMoveSound.sound.Play();
						player.isBoxCanMove = Moveable;
						index.SetIndex(xIndex, yIndex, Index::BOX);
						index.SetIndex(xIndex, yIndex + 1, Index::EMPTY); //set box location
						boxId = boxId_; //set box id
					}
				}
				break;

			case SDL_SCANCODE_LEFT: //player2
				if ((index.GetIndex(xIndex - 1, yIndex) == Index::LEVEL_COMPONENT::BOX) &&
					(b2Vec2(static_cast<float>(xIndex - 1.f), static_cast<float>(yIndex)) == GetIndexByBox(&box))) //check box is in front of the box
				{
					if (!index.IsObject(GetCharacterXIndex() - 2, GetCharacterYIndex()))
					{
						boxMoveSound.SetName("boxSlide");
						boxMoveSound.sound.LoadSound("sound/SlideBox.wav");
						boxMoveSound.sound.SetVolume(100);
						boxMoveSound.sound.Play();// soundeffect
						player.isBoxCanMove = Moveable;
						index.SetIndex(xIndex - 1, yIndex, Index::EMPTY);
						index.SetIndex(xIndex - 2, yIndex, Index::BOX);
						boxId = boxId_;
					}
				}
				break;

			case SDL_SCANCODE_RIGHT:
				if ((index.GetIndex(xIndex + 1, yIndex) == Index::LEVEL_COMPONENT::BOX) &&
					(b2Vec2(static_cast<float>(xIndex + 1.f), static_cast<float>(yIndex)) == GetIndexByBox(&box)))
				{
					if (!index.IsObject(GetCharacterXIndex() + 2, GetCharacterYIndex()))
					{
						boxMoveSound.SetName("boxSlide");
						boxMoveSound.sound.LoadSound("sound/SlideBox.wav");
						boxMoveSound.sound.SetVolume(100);
						boxMoveSound.sound.Play();
						player.isBoxCanMove = Moveable;
						index.SetIndex(xIndex + 1, yIndex, Index::EMPTY);
						index.SetIndex(xIndex + 2, yIndex, Index::BOX);
						boxId = boxId_;
					}
				}
				break;

			case SDL_SCANCODE_UP:
				if ((index.GetIndex(xIndex, yIndex + 1) == Index::LEVEL_COMPONENT::BOX) &&
					(b2Vec2(static_cast<float>(xIndex), static_cast<float>(yIndex + 1.f)) == GetIndexByBox(&box)))
				{
					if (!index.IsObject(GetCharacterXIndex(), GetCharacterYIndex() + 2))
					{
						boxMoveSound.SetName("boxSlide");
						boxMoveSound.sound.LoadSound("sound/SlideBox.wav");
						boxMoveSound.sound.SetVolume(100);
						boxMoveSound.sound.Play();
						player.isBoxCanMove = Moveable;
						index.SetIndex(xIndex, yIndex + 1, Index::EMPTY);
						index.SetIndex(xIndex, yIndex + 2, Index::BOX);
						boxId = boxId_;
					}
				}
				break;

			case SDL_SCANCODE_DOWN:
				if ((index.GetIndex(xIndex, yIndex - 1) == Index::LEVEL_COMPONENT::BOX) &&
					(b2Vec2(static_cast<float>(xIndex), static_cast<float>(yIndex - 1.f)) == GetIndexByBox(&box)))
				{
					if (!index.IsObject(GetCharacterXIndex(), GetCharacterYIndex() - 2))
					{
						boxMoveSound.SetName("boxSlide");
						boxMoveSound.sound.LoadSound("sound/SlideBox.wav");
						boxMoveSound.sound.SetVolume(100);
						boxMoveSound.sound.Play();
						player.isBoxCanMove = Moveable;
						index.SetIndex(xIndex, yIndex - 1, Index::EMPTY);
						index.SetIndex(xIndex, yIndex - 2, Index::BOX);
						boxId = boxId_;
					}
				}
				break;
			default:;
			}
		}
	}
}


void Character::PlayerMovement(SDL_Scancode input, Character& player) //function about player move's linear interpolation
{
	if (player.isPlayerPressable == cannot) //check player can press the button
	{
		switch (input)
		{
		case SDL_SCANCODE_A:
			player.transform.position.x -= MOVEMENT; //increase movement
			break;

		case SDL_SCANCODE_D:
			player.transform.position.x += MOVEMENT;
			break;

		case SDL_SCANCODE_W:
			player.transform.position.y += MOVEMENT;
			break;

		case SDL_SCANCODE_S:
			player.transform.position.y -= MOVEMENT;
			break;

		case SDL_SCANCODE_LEFT:
			player.transform.position.x -= MOVEMENT;
			break;

		case SDL_SCANCODE_RIGHT:
			player.transform.position.x += MOVEMENT;
			break;

		case SDL_SCANCODE_UP:
			player.transform.position.y += MOVEMENT;
			break;

		case SDL_SCANCODE_DOWN:
			player.transform.position.y -= MOVEMENT;
			break;
		default:;
		}
	}
}


void Character::BoxMovement(SDL_Scancode input, Character& player, Object& Box) //function about box move's linear interpolation
{
	if (player.isPlayerPressable == cannot) //check player can press the button
	{
		if (player.isBoxMovable == Enable) //check player can move the box
		{
			if (player.isBoxCanMove == Moveable) //check box can move
			{
				switch (input)
				{
				case SDL_SCANCODE_A:
					Box.transform.position.x -= MOVEMENT; //increase movement
					break;

				case SDL_SCANCODE_D:
					Box.transform.position.x += MOVEMENT;
					break;

				case SDL_SCANCODE_W:
					Box.transform.position.y += MOVEMENT;
					break;

				case SDL_SCANCODE_S:
					Box.transform.position.y -= MOVEMENT;
					break;

				case SDL_SCANCODE_LEFT:
					Box.transform.position.x -= MOVEMENT;
					break;

				case SDL_SCANCODE_RIGHT:
					Box.transform.position.x += MOVEMENT;
					break;

				case SDL_SCANCODE_UP:
					Box.transform.position.y += MOVEMENT;
					break;

				case SDL_SCANCODE_DOWN:
					Box.transform.position.y -= MOVEMENT;
					break;
				default:;
				}
			}
		}
	}
}


void Character::SetPlayer1SpriteStop(Character& player, Index& level) //function about set player1's stop sprite
{
	switch (player.GetDirection())
	{
	case Left:
		player.sprite.Free(); //free the sprite memory
		player.sprite.activeAnimation = false; //set animation false
		if ((level.GetIndex(xIndex - 1, yIndex) == Index::LEVEL_COMPONENT::BOX) && (player.isBoxMovable == Enable)) //check player's loaction behind the box
		{
			player.sprite.LoadImage("texture/RedLeftActive.png", State::m_renderer); //change sprite
		}
		else
		{
			player.sprite.LoadImage("texture/RedLeft.png", State::m_renderer); //change sprite
		}
		break;

	case Right:
		player.sprite.Free();
		player.sprite.activeAnimation = false;
		if ((level.GetIndex(xIndex + 1, yIndex) == Index::LEVEL_COMPONENT::BOX) && (player.isBoxMovable == Enable))
		{
			player.sprite.LoadImage("texture/RedRightActive.png", State::m_renderer);
		}
		else
		{
			player.sprite.LoadImage("texture/RedRight.png", State::m_renderer);
		}
		break;

	case Up:
		player.sprite.Free();
		player.sprite.activeAnimation = false;
		if ((level.GetIndex(xIndex, yIndex + 1) == Index::LEVEL_COMPONENT::BOX) && (player.isBoxMovable == Enable))
		{
			player.sprite.LoadImage("texture/RedUpActive.png", State::m_renderer);
		}
		else
		{
			player.sprite.LoadImage("texture/RedUp.png", State::m_renderer);
		}
		break;

	case Down:
		player.sprite.Free();
		player.sprite.activeAnimation = false;
		if ((level.GetIndex(xIndex, yIndex - 1) == Index::LEVEL_COMPONENT::BOX) && (player.isBoxMovable == Enable))
		{
			player.sprite.LoadImage("texture/RedDownActive.png", State::m_renderer);
		}
		else
		{
			player.sprite.LoadImage("texture/RedDown.png", State::m_renderer);
		}
		break;
	default:;
	}
}


void Character::SetPlayer2SpriteStop(Character& player, Index& level) //function about set player2's stop sprite
{
	switch (player.GetDirection())
	{
	case Left:
		player.sprite.Free(); //free the sprite memory
		player.sprite.activeAnimation = false; //set animation false
		if ((level.GetIndex(xIndex - 1, yIndex) == Index::LEVEL_COMPONENT::BOX) && (player.isBoxMovable == Enable)) //check player's loaction behind the box
		{
			player.sprite.LoadImage("texture/BlueLeftActive.png", State::m_renderer); //change sprite
		}
		else
		{
			player.sprite.LoadImage("texture/BlueLeft.png", State::m_renderer); //change sprite
		}
		break;

	case Right:
		player.sprite.Free();
		player.sprite.activeAnimation = false;
		if ((level.GetIndex(xIndex + 1, yIndex) == Index::LEVEL_COMPONENT::BOX) && (player.isBoxMovable == Enable))
		{
			player.sprite.LoadImage("texture/BlueRightActive.png", State::m_renderer);
		}
		else
		{
			player.sprite.LoadImage("texture/BlueRight.png", State::m_renderer);
		}
		break;

	case Up:
		player.sprite.Free();
		player.sprite.activeAnimation = false;
		if ((level.GetIndex(xIndex, yIndex + 1) == Index::LEVEL_COMPONENT::BOX) && (player.isBoxMovable == Enable))
		{
			player.sprite.LoadImage("texture/BlueUpActive.png", State::m_renderer);
		}
		else
		{
			player.sprite.LoadImage("texture/BlueUp.png", State::m_renderer);
		}
		break;

	case Down:
		player.sprite.Free();
		player.sprite.activeAnimation = false;
		if ((level.GetIndex(xIndex, yIndex - 1) == Index::LEVEL_COMPONENT::BOX) && (player.isBoxMovable == Enable))
		{
			player.sprite.LoadImage("texture/BlueDownActive.png", State::m_renderer);
		}
		else
		{
			player.sprite.LoadImage("texture/BlueDown.png", State::m_renderer);
		}
		break;
	default:;
	}
}


void Character::SetPlayer1SpriteMove(SDL_Scancode input, Index& level, Character& player) //function about set player1's move sprite
{
	switch (input)
	{
	case SDL_SCANCODE_A:
		if (!level.IsObject(GetCharacterXIndex() - 1, GetCharacterYIndex())) //check player can move
		{

			player.sprite.Free(); //free the sprite memory
			player.sprite.LoadImage("texture/RedLeftWalking.png", State::m_renderer); //change sprite
			player.sprite.activeAnimation = true;  //set animation false
			player.sprite.SetFrame(2); //set animation frame
			player.sprite.SetSpeed(ANIMATION_SPEED); //set animation speed

			if ((level.GetIndex(xIndex, yIndex) == Index::LEVEL_COMPONENT::BOX) && (player.isBoxMovable == Enable))  //check player's loaction behind the box
			{
				player.sprite.Free();
				player.sprite.LoadImage("texture/RedRightActiveWalking.png", State::m_renderer);
				player.sprite.activeAnimation = true;
				player.sprite.SetFrame(2);
				player.sprite.SetSpeed(ANIMATION_SPEED);
			}
		}
		break;

	case SDL_SCANCODE_D:
		if (!level.IsObject(GetCharacterXIndex() + 1, GetCharacterYIndex()))
		{
			player.sprite.Free();
			player.sprite.LoadImage("texture/RedRightWalking.png", State::m_renderer);
			player.sprite.activeAnimation = true;
			player.sprite.SetFrame(2);
			player.sprite.SetSpeed(ANIMATION_SPEED);
			if ((level.GetIndex(xIndex, yIndex) == Index::LEVEL_COMPONENT::BOX) && (player.isBoxMovable == Enable))
			{
				player.sprite.Free();
				player.sprite.LoadImage("texture/RedLeftActiveWalking.png", State::m_renderer);
				player.sprite.activeAnimation = true;
				player.sprite.SetFrame(2);
				player.sprite.SetSpeed(ANIMATION_SPEED);
			}
		}
		break;

	case SDL_SCANCODE_W:
		if (!level.IsObject(GetCharacterXIndex(), GetCharacterYIndex() + 1))
		{
			player.sprite.Free();
			player.sprite.LoadImage("texture/RedUpWalking.png", State::m_renderer);
			player.sprite.activeAnimation = true;
			player.sprite.SetFrame(2);
			player.sprite.SetSpeed(ANIMATION_SPEED);
			if ((level.GetIndex(xIndex, yIndex) == Index::LEVEL_COMPONENT::BOX) && (player.isBoxMovable == Enable))
			{
				player.sprite.Free();
				player.sprite.LoadImage("texture/RedDownActiveWalking.png", State::m_renderer);
				player.sprite.activeAnimation = true;
				player.sprite.SetFrame(2);
				player.sprite.SetSpeed(ANIMATION_SPEED);
			}
		}
		break;

	case SDL_SCANCODE_S:
		if (!level.IsObject(GetCharacterXIndex(), GetCharacterYIndex() - 1))
		{
			player.sprite.Free();
			player.sprite.LoadImage("texture/RedDownWalking.png", State::m_renderer);
			player.sprite.activeAnimation = true;
			player.sprite.SetFrame(2);
			player.sprite.SetSpeed(ANIMATION_SPEED);
			if ((level.GetIndex(xIndex, yIndex) == Index::LEVEL_COMPONENT::BOX) && (player.isBoxMovable == Enable))
			{
				player.sprite.Free();
				player.sprite.LoadImage("texture/RedUpActiveWalking.png", State::m_renderer);
				player.sprite.activeAnimation = true;
				player.sprite.SetFrame(2);
				player.sprite.SetSpeed(ANIMATION_SPEED);
			}
		}
		break;
	default:;
	}
}


void Character::SetPlayer2SpriteMove(SDL_Scancode input, Index& level, Character& player) //function about set player2's move sprite
{
	switch (input)
	{
	case SDL_SCANCODE_LEFT:
		if (!level.IsObject(GetCharacterXIndex() - 1, GetCharacterYIndex())) //check player can move
		{
			player.sprite.Free();
			player.sprite.LoadImage("texture/BlueLeftWalking.png", State::m_renderer); //change sprite
			player.sprite.activeAnimation = true;  //set animation false
			player.sprite.SetFrame(2); //set animation frame
			player.sprite.SetSpeed(ANIMATION_SPEED); //set animation speed
			if ((level.GetIndex(xIndex - 2, yIndex) == Index::LEVEL_COMPONENT::BOX) && (player.isBoxMovable == Enable))  //check player's loaction behind the box
			{
				player.sprite.Free();
				player.sprite.LoadImage("texture/BlueLeftActiveWalking.png", State::m_renderer);
				player.sprite.activeAnimation = true;
				player.sprite.SetFrame(2);
				player.sprite.SetSpeed(ANIMATION_SPEED);
			}
		}
		break;

	case SDL_SCANCODE_RIGHT:
		if (!level.IsObject(GetCharacterXIndex() + 1, GetCharacterYIndex()))
		{
			player.sprite.Free();
			player.sprite.LoadImage("texture/BlueRightWalking.png", State::m_renderer);
			player.sprite.activeAnimation = true;
			player.sprite.SetFrame(2);
			player.sprite.SetSpeed(ANIMATION_SPEED);
			if ((level.GetIndex(xIndex + 2, yIndex) == Index::LEVEL_COMPONENT::BOX) && (player.isBoxMovable == Enable))
			{
				player.sprite.Free();
				player.sprite.LoadImage("texture/BlueRightActiveWalking.png", State::m_renderer);
				player.sprite.activeAnimation = true;
				player.sprite.SetFrame(2);
				player.sprite.SetSpeed(ANIMATION_SPEED);
			}
		}
		break;

	case SDL_SCANCODE_UP:
		if (!level.IsObject(GetCharacterXIndex(), GetCharacterYIndex() + 1))
		{
			player.sprite.Free();
			player.sprite.LoadImage("texture/BlueUpWalking.png", State::m_renderer);
			player.sprite.activeAnimation = true;
			player.sprite.SetFrame(2);
			player.sprite.SetSpeed(ANIMATION_SPEED);
			if ((level.GetIndex(xIndex, yIndex + 2) == Index::LEVEL_COMPONENT::BOX) && (player.isBoxMovable == Enable))
			{
				player.sprite.Free();
				player.sprite.LoadImage("texture/BlueUpActiveWalking.png", State::m_renderer);
				player.sprite.activeAnimation = true;
				player.sprite.SetFrame(2);
				player.sprite.SetSpeed(ANIMATION_SPEED);
			}
		}
		break;

	case SDL_SCANCODE_DOWN:
		if (!level.IsObject(GetCharacterXIndex(), GetCharacterYIndex() - 1))
		{
			player.sprite.Free();
			player.sprite.LoadImage("texture/BlueDownWalking.png", State::m_renderer);
			player.sprite.activeAnimation = true;
			player.sprite.SetFrame(2);
			player.sprite.SetSpeed(ANIMATION_SPEED);
			if ((level.GetIndex(xIndex, yIndex - 2) == Index::LEVEL_COMPONENT::BOX) && (player.isBoxMovable == Enable))
			{
				player.sprite.Free();
				player.sprite.LoadImage("texture/BlueDownActiveWalking.png", State::m_renderer);
				player.sprite.activeAnimation = true;
				player.sprite.SetFrame(2);
				player.sprite.SetSpeed(ANIMATION_SPEED);
			}
		}
		break;
	default:;
	}
}
