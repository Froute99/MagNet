/**************************************************************************************
File Name    : Level8.cpp
Project name : MaG+NeT
Author	     : Junghak Kim
Email	     : dbh99619@gmail.com
Copyright Information :
    "All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/

#include "Level8.h"
#include "CommonLevel.h"
#include "CreateObject.h"
#include "Player1BoxMove.h"
#include "Player1Controller.h"
#include "Player2BoxMove.h"
#include "Player2Controller.h"

void Level8::Initialize()
{
	Music.SetName("Music");
	Music.sound.LoadSound("sound/nekzlo-storieschillroyaltyfreemusic-Awqs6d9A.mp3");
	Music.sound.SetVolume(55);
	Music.sound.Play();

    const int width = level8.GetWidth();
    const int height = level8.GetHeight();

	State::sCurrentState = this;

	for (int i = 0; i < width; i++)
	{
		level8.SetIndex(i, 0, Index::WALL);
		level8.SetIndex(i, height - 1, Index::WALL);
	}
	for (int i = 0; i < height; i++)
	{
		level8.SetIndex(0, i, Index::WALL);
		level8.SetIndex(width - 1, i, Index::WALL);
	}
	level8.SetIndex(2, 1, Index::WALL);
	level8.SetIndex(2, 2, Index::WALL);
	level8.SetIndex(4, 1, Index::WALL);
	level8.SetIndex(4, 2, Index::WALL);
	level8.SetIndex(4, 4, Index::WALL);
	level8.SetIndex(4, 5, Index::WALL);
	level8.SetIndex(4, 6, Index::WALL);
	level8.SetIndex(4, 7, Index::WALL);
	level8.SetIndex(4, 8, Index::WALL);
	level8.SetIndex(4, 9, Index::WALL);
	level8.SetIndex(1, 5, Index::WALL);
	level8.SetIndex(1, 6, Index::WALL);
	level8.SetIndex(1, 7, Index::WALL);
	level8.SetIndex(3, 6, Index::WALL);
	level8.SetIndex(3, 7, Index::WALL);

	Player1.SetCharacterXIndex(3);
	Player1.SetCharacterYIndex(1);
	Player2.SetCharacterXIndex(1);
	Player2.SetCharacterYIndex(1);
	level8.SetIndex(Player1.GetCharacterXIndex(), Player1.GetCharacterYIndex(), Index::MAG);
	level8.SetIndex(Player2.GetCharacterXIndex(), Player2.GetCharacterYIndex(), Index::NET);
	Player1.SetMovableStatus(Character::Unable);
	Player2.SetMovableStatus(Character::Unable);

	level8.InitializeMapTile(width, height);

	level8.SetIndex(2, 3, Index::BOX);
	level8.SetIndex(2, 4, Index::BOX);
	level8.SetIndex(2, 5, Index::BOX);
	level8.SetIndex(3, 4, Index::BOX);

	player1Clear.SetClearMagXIndex(3);
	player1Clear.SetClearMagYIndex(8);
	player2Clear.SetClearNetXIndex(1);
	player2Clear.SetClearNetYIndex(8);
    level8.SetIndex(player1Clear.GetClearMagXIndex(), player1Clear.GetClearMagYIndex(), Index::CLEAR_MAG);
    level8.SetIndex(player2Clear.GetClearNetXIndex(), player2Clear.GetClearNetYIndex(), Index::CLEAR_NET);
    MakeObject(player1Clear, "MagClear", static_cast<float>(player1Clear.GetClearMagXIndex()), static_cast<float>(player1Clear.GetClearMagYIndex()));
    MakeObject(player2Clear, "NetClear", static_cast<float>(player2Clear.GetClearNetXIndex()), static_cast<float>(player2Clear.GetClearNetYIndex()));

	MakeObject(Box1, "Box1", 2, 3);
	Box1.sprite.LoadImage("texture/Box.png", State::m_renderer);
	MakeObject(Box2, "Box2", 2, 4);
	Box2.sprite.LoadImage("texture/Box.png", State::m_renderer);
	MakeObject(Box3, "Box3", 2, 5);
	Box3.sprite.LoadImage("texture/Box.png", State::m_renderer);
	MakeObject(Box4, "Box4", 3, 4);
	Box4.sprite.LoadImage("texture/Box.png", State::m_renderer);

	Component*         pComp = AddComponentToObject(&Player1, eComponentTypes::Player1Controller);
	Player1Controller* controller = dynamic_cast<Player1Controller*>(pComp);
	controller->Player1 = &Player1;
	controller->Level = &level8;
	controller->Boxes.push_back(&Box1);
	controller->Boxes.push_back(&Box2);
	controller->Boxes.push_back(&Box3);
	controller->Boxes.push_back(&Box4);

	Component*         pComp1 = AddComponentToObject(&Player2, eComponentTypes::Player2Controller);
	Player2Controller* controller1 = dynamic_cast<Player2Controller*>(pComp1);
	controller1->Player2 = &Player2;
	controller1->Level = &level8;
	controller1->Boxes.push_back(&Box1);
	controller1->Boxes.push_back(&Box2);
	controller1->Boxes.push_back(&Box3);
	controller1->Boxes.push_back(&Box4);

	Component*      pCompM = AddComponentToObject(&Player1, eComponentTypes::Player1BoxMove);
	Component*      pCompM2 = AddComponentToObject(&Player2, eComponentTypes::Player2BoxMove);
	Player1BoxMove* BoxMove = dynamic_cast<Player1BoxMove*>(pCompM);
	Player2BoxMove* BoxMove1 = dynamic_cast<Player2BoxMove*>(pCompM2);
	BoxMove->Player1 = &Player1;
	BoxMove1->Player2 = &Player2;
	BoxMove->Level = &level8;
	BoxMove1->Level = &level8;

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			switch (level8.GetIndex(x, y))
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


	// Set background color
	m_backgroundColor = MapColor::BLACK;
	// Set position of the camera
	camera.position.Set(100, 200, -20);
	State::m_pCamera = &camera;

    levelSign.SetName("LevelSign");
	levelSign.transform.SetScale(250.f, 50.f);
	levelSign.sprite.LoadImage("texture/LevelSign8.png", m_renderer);
	levelSign.sprite.isHud = true;
	levelSign.transform.position.Set(-425.f, 200.f, 1.f);
	AddObject(&levelSign);
}

void Level8::Update(float dt)
{
	UpdateObjects(dt);

	if (m_input->IsTriggered(SDL_SCANCODE_R))
		m_game->Restart();
	if ((level8.GetIndex(Player1.GetCharacterXIndex(), Player1.GetCharacterYIndex()) ==
		level8.GetIndex(player1Clear.GetClearMagXIndex(), player1Clear.GetClearMagYIndex())) &&
		(level8.GetIndex(Player2.GetCharacterXIndex(), Player2.GetCharacterYIndex()) ==
			level8.GetIndex(player2Clear.GetClearNetXIndex(), player2Clear.GetClearNetYIndex())))
	{
		m_game->SetLevelId(8);
		m_game->Change(LV_ClearScreen);
	}
	// Must be one of the last functions called at the end of State Update
	if (m_input->IsTriggered(SDL_SCANCODE_PAGEDOWN))
	{
		m_game->Change(LV_Level7);
	}
	else if (m_input->IsTriggered(SDL_SCANCODE_PAGEUP))
	{
		m_game->Change(LV_Level9);
	}

	Render(dt);
}

void Level8::Close()
{
	// Wrap up state
	ClearBaseState();
	Music.sound.Free();
	level8.InitializeIndex();
}
