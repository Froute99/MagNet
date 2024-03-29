/**************************************************************************************
File Name    : Level10.cpp
Project name : MaG+NeT
Author	     : Jihoon Kim
Email	     : jihoon1602@gmail.com
Copyright Information :
    "All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/

#include "CommonLevel.h"
#include "CreateObject.h"
#include "Player1Controller.h"
#include "Player2Controller.h"
#include "Player1BoxMove.h"
#include "Player2BoxMove.h"
#include "Level10.h"

void Level10::Initialize()
{
	Music.SetName("Music");
	Music.sound.LoadSound("sound/nekzlo-storieschillroyaltyfreemusic-Awqs6d9A.mp3");
	Music.sound.SetVolume(55);
	Music.sound.Play();

	const int width = level10.GetWidth();
	const int height = level10.GetHeight();

	State::sCurrentState = this;

	for (int i = 0; i < width; i++)
	{
		level10.SetIndex(i, 0, Index::WALL);
		level10.SetIndex(i, height - 1, Index::WALL);
	}
	for (int i = 0; i < height; i++)
	{
		level10.SetIndex(0, i, Index::WALL);
		level10.SetIndex(width - 1, i, Index::WALL);
	}
	level10.SetIndex(1, 1, Index::WALL);
	level10.SetIndex(1, 2, Index::WALL);
	level10.SetIndex(1, 3, Index::WALL);
	level10.SetIndex(1, 4, Index::WALL);
	level10.SetIndex(1, 5, Index::WALL);
	level10.SetIndex(2, 1, Index::WALL);
	level10.SetIndex(2, 1, Index::WALL);
	level10.SetIndex(2, 2, Index::WALL);
	level10.SetIndex(2, 3, Index::WALL);
	level10.SetIndex(2, 4, Index::WALL);
	level10.SetIndex(2, 5, Index::WALL);
	level10.SetIndex(2, 7, Index::WALL);
	level10.SetIndex(3, 1, Index::WALL);
	level10.SetIndex(3, 4, Index::WALL);
	level10.SetIndex(3, 5, Index::WALL);
	level10.SetIndex(3, 7, Index::WALL);
	level10.SetIndex(4, 7, Index::WALL);
	level10.SetIndex(5, 1, Index::WALL);
	level10.SetIndex(5, 2, Index::WALL);
	level10.SetIndex(5, 6, Index::WALL);
	level10.SetIndex(5, 7, Index::WALL);
	level10.SetIndex(6, 7, Index::WALL);
	level10.SetIndex(7, 1, Index::WALL);
	level10.SetIndex(7, 4, Index::WALL);
	level10.SetIndex(7, 5, Index::WALL);
	level10.SetIndex(7, 7, Index::WALL);
	level10.SetIndex(8, 1, Index::WALL);
	level10.SetIndex(8, 2, Index::WALL);
	level10.SetIndex(8, 3, Index::WALL);
	level10.SetIndex(8, 4, Index::WALL);
	level10.SetIndex(8, 5, Index::WALL);
	level10.SetIndex(8, 7, Index::WALL);
	level10.SetIndex(9, 1, Index::WALL);
	level10.SetIndex(9, 2, Index::WALL);
	level10.SetIndex(9, 3, Index::WALL);
	level10.SetIndex(9, 4, Index::WALL);
	level10.SetIndex(9, 5, Index::WALL);

	Player1.SetCharacterXIndex(6);
	Player1.SetCharacterYIndex(1);
	Player2.SetCharacterXIndex(4);
	Player2.SetCharacterYIndex(1);
	level10.SetIndex(Player1.GetCharacterXIndex(), Player1.GetCharacterYIndex(), Index::MAG);
	level10.SetIndex(Player2.GetCharacterXIndex(), Player2.GetCharacterYIndex(), Index::NET);
	Player1.SetMovableStatus(Character::Unable);
	Player2.SetMovableStatus(Character::Unable);

	level10.SetIndex(4, 4, Index::BOX);
	level10.SetIndex(4, 5, Index::BOX);
	level10.SetIndex(5, 4, Index::BOX);
	level10.SetIndex(6, 4, Index::BOX);
	level10.SetIndex(6, 5, Index::BOX);

	level10.InitializeMapTile(width, height);

	player1Clear.SetClearMagXIndex(9);
	player1Clear.SetClearMagYIndex(7);
	player2Clear.SetClearNetXIndex(1);
	player2Clear.SetClearNetYIndex(7);
    level10.SetIndex(player1Clear.GetClearMagXIndex(), player1Clear.GetClearMagYIndex(), Index::CLEAR_MAG);
    level10.SetIndex(player2Clear.GetClearNetXIndex(), player2Clear.GetClearNetYIndex(), Index::CLEAR_NET);
    MakeObject(player1Clear, "MagClear", static_cast<float>(player1Clear.GetClearMagXIndex()), static_cast<float>(player1Clear.GetClearMagYIndex()));
    MakeObject(player2Clear, "NetClear", static_cast<float>(player2Clear.GetClearNetXIndex()), static_cast<float>(player2Clear.GetClearNetYIndex()));

	Component*         pComp = AddComponentToObject(&Player1, eComponentTypes::Player1Controller);
	Player1Controller* controller = dynamic_cast<Player1Controller*>(pComp);
	controller->Player1 = &Player1;
	controller->Level = &level10;
	controller->Boxes.push_back(&Box1);
	controller->Boxes.push_back(&Box2);
	controller->Boxes.push_back(&Box3);
	controller->Boxes.push_back(&Box4);
	controller->Boxes.push_back(&Box5);

	Component*         pComp1 = AddComponentToObject(&Player2, eComponentTypes::Player2Controller);
	Player2Controller* controller1 = dynamic_cast<Player2Controller*>(pComp1);
	controller1->Player2 = &Player2;
	controller1->Level = &level10;
	controller1->Boxes.push_back(&Box1);
	controller1->Boxes.push_back(&Box2);
	controller1->Boxes.push_back(&Box3);
	controller1->Boxes.push_back(&Box4);
	controller1->Boxes.push_back(&Box5);

	Component*         pCompM = AddComponentToObject(&Player1, eComponentTypes::Player1BoxMove);
	Component*         pCompM2 = AddComponentToObject(&Player2, eComponentTypes::Player2BoxMove);
	Player1BoxMove* BoxMove = dynamic_cast<Player1BoxMove*>(pCompM);
	Player2BoxMove* BoxMove1 = dynamic_cast<Player2BoxMove*>(pCompM2);
	BoxMove->Player1 = &Player1;
	BoxMove1->Player2 = &Player2;
	BoxMove->Level = &level10;
	BoxMove1->Level = &level10;

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			switch (level10.GetIndex(x, y))
			{
			case Index::LEVEL_COMPONENT::WALL:
				CreateWall(float(x), float(y));
				break;
			case Index::LEVEL_COMPONENT::MAG:
				MakeObject(Player1, "Mag", float(x), float(y));
				Player1.sprite.LoadImage("texture/RedDown.png", State::m_renderer);
				break;
			case Index::LEVEL_COMPONENT::NET:
				MakeObject(Player2, "Net", float(x), float(y));
				Player2.sprite.LoadImage("texture/BlueDown.png", State::m_renderer);
				break;
			case Index::LEVEL_COMPONENT::CLEAR_MAG:
				player1Clear.sprite.color = MapColor::CLEAR_MAG_COLOR;
				break;
			case Index::LEVEL_COMPONENT::CLEAR_NET:
				player2Clear.sprite.color = MapColor::CLEAR_NET_COLOR;
			default:;
			}
		}
	}

	MakeObject(Box1, "Box1", 4, 4);
	Box1.sprite.LoadImage("texture/Box.png", State::m_renderer);
	MakeObject(Box2, "Box2", 4, 5);
	Box2.sprite.LoadImage("texture/Box.png", State::m_renderer);
	MakeObject(Box3, "Box3", 5, 4);
	Box3.sprite.LoadImage("texture/Box.png", State::m_renderer);
	MakeObject(Box4, "Box4", 6, 4);
	Box4.sprite.LoadImage("texture/Box.png", State::m_renderer);
	MakeObject(Box5, "Box5", 6, 5);
	Box5.sprite.LoadImage("texture/Box.png", State::m_renderer);

	// Set background color
	m_backgroundColor = MapColor::BLACK;
	// Set position of the camera
	camera.position.Set(200, 135, -20);
    State::m_pCamera = &camera;

	levelSign.SetName("LevelSign");
	levelSign.transform.SetScale(250.f, 50.f);
	levelSign.sprite.LoadImage("texture/LevelSign10.png", m_renderer);
	levelSign.sprite.isHud = true;
	levelSign.transform.position.Set(-425.f, 200.f, 1.f);
	AddObject(&levelSign);
}


void Level10::Update(float dt)
{
	UpdateObjects(dt);

	if (m_input->IsTriggered(SDL_SCANCODE_R))
		m_game->Restart();


	if ((level10.GetIndex(Player1.GetCharacterXIndex(), Player1.GetCharacterYIndex()) ==
		level10.GetIndex(player1Clear.GetClearMagXIndex(), player1Clear.GetClearMagYIndex())) &&
		(level10.GetIndex(Player2.GetCharacterXIndex(), Player2.GetCharacterYIndex()) ==
			level10.GetIndex(player2Clear.GetClearNetXIndex(), player2Clear.GetClearNetYIndex())))
	{
		m_game->SetLevelId(10);
		m_game->Change(LV_ClearScreen);
	}
	// Must be one of the last functions called at the end of State Update
	if (m_input->IsTriggered(SDL_SCANCODE_PAGEDOWN))
	{
		m_game->Change(LV_Level9);
	}
	else if (m_input->IsTriggered(SDL_SCANCODE_PAGEUP))
	{
		m_game->Change(LV_Level11);
	}

	Render(dt);
}


void Level10::Close()
{
	// Wrap up state
	ClearBaseState();
	Music.sound.Free();
	level10.InitializeIndex();
}
