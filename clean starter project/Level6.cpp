/**************************************************************************************
File Name    : Level6.cpp
Project name : MaG+NeT
Author	     : Eunjin Hong
Email	     : chocob0217@gmail.com
Copyright Information :
    "All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/#include "CommonLevel.h"
#include "CreateObject.h"
#include "Player1Controller.h"
#include "Player2Controller.h"
#include "Player1BoxMove.h"
#include "Player2BoxMove.h"
#include "Level6.h"

void Level6::Initialize()
{
	Music.SetName("Music");
	Music.sound.LoadSound("sound/nekzlo-storieschillroyaltyfreemusic-Awqs6d9A.mp3");
	Music.sound.SetVolume(50);
	Music.sound.Play();

	const int width = level6.GetWidth();
	const int height = level6.GetHeight();

    State::sCurrentState = this;

	for (int i = 0; i < width; i++)
	{
		level6.SetIndex(i, 0, Index::WALL);
		level6.SetIndex(i, height - 1, Index::WALL);
	}
	for (int i = 0; i < height; i++)
	{
		level6.SetIndex(0, i, Index::WALL);
		level6.SetIndex(width - 1, i, Index::WALL);
	}
	for (int i = 1; i <= 8; i++)
	{
		level6.SetIndex(5, i, Index::WALL);
	}
	level6.SetIndex(2, 10, Index::WALL);
	level6.SetIndex(3, 10, Index::WALL);
	level6.SetIndex(4, 10, Index::WALL);
	level6.SetIndex(2, 9, Index::WALL);
	level6.SetIndex(3, 1, Index::WALL);
	level6.SetIndex(3, 9, Index::WALL);
	level6.SetIndex(1, 1, Index::WALL);
	level6.SetIndex(1, 4, Index::WALL);
	level6.SetIndex(1, 5, Index::WALL);
	level6.SetIndex(1, 6, Index::WALL);
	level6.SetIndex(1, 7, Index::WALL);
	level6.SetIndex(3, 4, Index::WALL);
	level6.SetIndex(3, 5, Index::WALL);
	level6.SetIndex(3, 6, Index::WALL);

    Player1.SetCharacterXIndex(2);
	Player1.SetCharacterYIndex(1);
	Player2.SetCharacterXIndex(4);
	Player2.SetCharacterYIndex(1);
	level6.SetIndex(Player1.GetCharacterXIndex(), Player1.GetCharacterYIndex(), Index::MAG);
	level6.SetIndex(Player2.GetCharacterXIndex(), Player2.GetCharacterYIndex(), Index::NET);
	Player1.SetMovableStatus(Character::Unable);
	Player2.SetMovableStatus(Character::Unable);

    Player1.SetCharacterXIndex(2);
    Player1.SetCharacterYIndex(1);
    Player2.SetCharacterXIndex(4);
    Player2.SetCharacterYIndex(1);
    level6.SetIndex(Player1.GetCharacterXIndex(), Player1.GetCharacterYIndex(), Index::MAG);
    level6.SetIndex(Player2.GetCharacterXIndex(), Player2.GetCharacterYIndex(), Index::NET);
    Player1.SetMovableStatus(Character::Unable);
    Player2.SetMovableStatus(Character::Unable);

	level6.SetIndex(2, 5, Index::BOX);
	level6.SetIndex(2, 7, Index::BOX);
	level6.SetIndex(2, 8, Index::BOX);
	level6.SetIndex(4, 3, Index::BOX);
	level6.SetIndex(4, 8, Index::BOX);

	level6.InitializeMapTile(width, height);

	player1Clear.SetClearMagXIndex(1);
	player1Clear.SetClearMagYIndex(10);
	player2Clear.SetClearNetXIndex(5);
	player2Clear.SetClearNetYIndex(10);
    level6.SetIndex(player1Clear.GetClearMagXIndex(), player1Clear.GetClearMagYIndex(), Index::CLEAR_MAG);
    level6.SetIndex(player2Clear.GetClearNetXIndex(), player2Clear.GetClearNetYIndex(), Index::CLEAR_NET);
    MakeObject(player1Clear, "MagClear", static_cast<float>(player1Clear.GetClearMagXIndex()), static_cast<float>(player1Clear.GetClearMagYIndex()));
    MakeObject(player2Clear, "NetClear", static_cast<float>(player2Clear.GetClearNetXIndex()), static_cast<float>(player2Clear.GetClearNetYIndex()));

	Component*         pComp = AddComponentToObject(&Player1, eComponentTypes::Player1Controller);
	Player1Controller* controller = dynamic_cast<Player1Controller*>(pComp);
	controller->Player1 = &Player1;
	controller->Level = &level6;
	controller->Boxes.push_back(&Box1);
	controller->Boxes.push_back(&Box2);
	controller->Boxes.push_back(&Box3);
	controller->Boxes.push_back(&Box4);
	controller->Boxes.push_back(&Box5);

	Component*         pComp1 = AddComponentToObject(&Player2, eComponentTypes::Player2Controller);
	Player2Controller* controller1 = dynamic_cast<Player2Controller*>(pComp1);
	controller1->Player2 = &Player2;
	controller1->Level = &level6;
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
	BoxMove->Level = &level6;
	BoxMove1->Level = &level6;

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			switch (level6.GetIndex(x, y))
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

	MakeObject(Box1, "Box1", 2, 5);
	Box1.sprite.LoadImage("texture/Box.png", State::m_renderer);
	MakeObject(Box2, "Box2", 2, 7);
	Box2.sprite.LoadImage("texture/Box.png", State::m_renderer);
	MakeObject(Box3, "Box1", 2, 8);
	Box3.sprite.LoadImage("texture/Box.png", State::m_renderer);
	MakeObject(Box4, "Box2", 4, 3);
	Box4.sprite.LoadImage("texture/Box.png", State::m_renderer);
	MakeObject(Box5, "Box2", 4, 8);
	Box5.sprite.LoadImage("texture/Box.png", State::m_renderer);

	// Set background color
	m_backgroundColor = MapColor::BLACK;
	// Set position of the camera
	camera.position.Set(150, 250, -20);
	State::m_pCamera = &camera;

	levelSign.SetName("LevelSign");
	levelSign.transform.SetScale(250.f, 50.f);
	levelSign.sprite.LoadImage("texture/LevelSign6.png", m_renderer);
	levelSign.sprite.isHud = true;
	levelSign.transform.position.Set(-425.f, 200.f, 1.f);
	AddObject(&levelSign);
}


void Level6::Update(float dt)
{
	UpdateObjects(dt);

	if (m_input->IsTriggered(SDL_SCANCODE_R))
		m_game->Restart();

	if ((level6.GetIndex(Player1.GetCharacterXIndex(), Player1.GetCharacterYIndex()) ==
		level6.GetIndex(player1Clear.GetClearMagXIndex(), player1Clear.GetClearMagYIndex())) &&
		(level6.GetIndex(Player2.GetCharacterXIndex(), Player2.GetCharacterYIndex()) ==
			level6.GetIndex(player2Clear.GetClearNetXIndex(), player2Clear.GetClearNetYIndex())))
	{
		m_game->SetLevelId(6);
		m_game->Change(LV_ClearScreen);
	}
	// Must be one of the last functions called at the end of State Update
	if (m_input->IsTriggered(SDL_SCANCODE_PAGEDOWN))
	{
		m_game->Change(LV_Level5);
	}
	else if (m_input->IsTriggered(SDL_SCANCODE_PAGEUP))
	{
		m_game->Change(LV_Level7);
	}

	Render(dt);
}


void Level6::Close()
{
	// Wrap up state
	ClearBaseState();
	Music.sound.Free();
	level6.InitializeIndex();
}
