/**************************************************************************************
File Name    : Level11.cpp
Project name : MaG+NeT
Author	     : Junghak Kim
Email	     : dbh99619@gmail.com
Copyright Information :
    "All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/

#include "CommonLevel.h"
#include "CreateObject.h"
#include "Player1Controller.h"
#include "Player2Controller.h"
#include "Player1BoxMove.h"
#include "Player2BoxMove.h"
#include "Level11.h"

void Level11::Initialize()
{
	Music.SetName("Music");
	Music.sound.LoadSound("sound/nekzlo-storieschillroyaltyfreemusic-Awqs6d9A.mp3");
	Music.sound.SetVolume(55);
	Music.sound.Play();

	const int width = 7;
	const int height = 11;

	State::sCurrentState = this;

	for (int i = 0; i < width; i++)
	{
		level11.SetIndex(i, 0, Index::WALL);
		level11.SetIndex(i, height - 1, Index::WALL);
	}
	for (int i = 0; i < height; i++)
	{
		level11.SetIndex(0, i, Index::WALL);
		level11.SetIndex(width - 1, i, Index::WALL);
	}
	level11.SetIndex(2, 1, Index::WALL);
	level11.SetIndex(3, 1, Index::WALL);
	level11.SetIndex(4, 1, Index::WALL);
	level11.SetIndex(2, 9, Index::WALL);
	level11.SetIndex(3, 9, Index::WALL);
	level11.SetIndex(4, 9, Index::WALL);
	level11.SetIndex(1, 5, Index::WALL);
	level11.SetIndex(3, 5, Index::WALL);
	level11.SetIndex(5, 5, Index::WALL);

	Player1.SetCharacterXIndex(1);
	Player1.SetCharacterYIndex(9);
	Player2.SetCharacterXIndex(5);
	Player2.SetCharacterYIndex(9);
	level11.SetIndex(Player1.GetCharacterXIndex(), Player1.GetCharacterYIndex(), Index::MAG);
	level11.SetIndex(Player2.GetCharacterXIndex(), Player2.GetCharacterYIndex(), Index::NET);
	Player1.SetMovableStatus(Character::Unable);
	Player2.SetMovableStatus(Character::Unable);

    level11.InitializeMapTile(width, height);

	level11.SetIndex(1, 2, Index::BOX);
	level11.SetIndex(3, 2, Index::BOX);
	level11.SetIndex(5, 2, Index::BOX);
	level11.SetIndex(2, 3, Index::BOX);
	level11.SetIndex(4, 3, Index::BOX);
	level11.SetIndex(1, 4, Index::BOX);
	level11.SetIndex(3, 4, Index::BOX);
	level11.SetIndex(5, 4, Index::BOX);
	level11.SetIndex(2, 5, Index::BOX);
	level11.SetIndex(4, 5, Index::BOX);
	level11.SetIndex(1, 6, Index::BOX);
	level11.SetIndex(3, 6, Index::BOX);
	level11.SetIndex(5, 6, Index::BOX);
	level11.SetIndex(2, 7, Index::BOX);
	level11.SetIndex(4, 7, Index::BOX);
	level11.SetIndex(3, 8, Index::BOX);

	player1Clear.SetClearMagXIndex(1);
	player1Clear.SetClearMagYIndex(1);
	player2Clear.SetClearNetXIndex(5);
	player2Clear.SetClearNetYIndex(1);
    level11.SetIndex(player1Clear.GetClearMagXIndex(), player1Clear.GetClearMagYIndex(), Index::CLEAR_MAG);
    level11.SetIndex(player2Clear.GetClearNetXIndex(), player2Clear.GetClearNetYIndex(), Index::CLEAR_NET);
    MakeObject(player1Clear, "MagClear", static_cast<float>(player1Clear.GetClearMagXIndex()), static_cast<float>(player1Clear.GetClearMagYIndex()));
    MakeObject(player2Clear, "NetClear", static_cast<float>(player2Clear.GetClearNetXIndex()), static_cast<float>(player2Clear.GetClearNetYIndex()));

	MakeObject(Box1, "Box1", 1, 2);
	Box1.sprite.LoadImage("texture/Box.png", State::m_renderer);
	MakeObject(Box2, "Box2", 3, 2);
	Box2.sprite.LoadImage("texture/Box.png", State::m_renderer);
	MakeObject(Box3, "Box3", 5, 2);
	Box3.sprite.LoadImage("texture/Box.png", State::m_renderer);
	MakeObject(Box4, "Box4", 2, 3);
	Box4.sprite.LoadImage("texture/Box.png", State::m_renderer);
	MakeObject(Box5, "Box5", 4, 3);
	Box5.sprite.LoadImage("texture/Box.png", State::m_renderer);
	MakeObject(Box6, "Box6", 1, 4);
	Box6.sprite.LoadImage("texture/Box.png", State::m_renderer);
	MakeObject(Box7, "Box7", 3, 4);
	Box7.sprite.LoadImage("texture/Box.png", State::m_renderer);
	MakeObject(Box8, "Box8", 5, 4);
	Box8.sprite.LoadImage("texture/Box.png", State::m_renderer);
	MakeObject(Box9, "Box9", 2, 5);
	Box9.sprite.LoadImage("texture/Box.png", State::m_renderer);
	MakeObject(Box10, "Box10", 4, 5);
	Box10.sprite.LoadImage("texture/Box.png", State::m_renderer);
	MakeObject(Box11, "Box11", 1, 6);
	Box11.sprite.LoadImage("texture/Box.png", State::m_renderer);
	MakeObject(Box12, "Box12", 3, 6);
	Box12.sprite.LoadImage("texture/Box.png", State::m_renderer);
	MakeObject(Box13, "Box13", 5, 6);
	Box13.sprite.LoadImage("texture/Box.png", State::m_renderer);
	MakeObject(Box14, "Box14", 2, 7);
	Box14.sprite.LoadImage("texture/Box.png", State::m_renderer);
	MakeObject(Box15, "Box15", 4, 7);
	Box15.sprite.LoadImage("texture/Box.png", State::m_renderer);
	MakeObject(Box16, "Box16", 3, 8);
	Box16.sprite.LoadImage("texture/Box.png", State::m_renderer);

	Component*         pComp      = AddComponentToObject(&Player1, eComponentTypes::Player1Controller);
	Player1Controller* controller = dynamic_cast<Player1Controller*>(pComp);
	controller->Player1           = &Player1;
	controller->Level             = &level11;
	controller->Boxes.push_back(&Box1);
	controller->Boxes.push_back(&Box2);
	controller->Boxes.push_back(&Box3);
	controller->Boxes.push_back(&Box4);
	controller->Boxes.push_back(&Box5);
	controller->Boxes.push_back(&Box6);
	controller->Boxes.push_back(&Box7);
	controller->Boxes.push_back(&Box8);
	controller->Boxes.push_back(&Box9);
	controller->Boxes.push_back(&Box10);
	controller->Boxes.push_back(&Box11);
	controller->Boxes.push_back(&Box12);
	controller->Boxes.push_back(&Box13);
	controller->Boxes.push_back(&Box14);
	controller->Boxes.push_back(&Box15);
	controller->Boxes.push_back(&Box16);

	Component*         pComp1      = AddComponentToObject(&Player2, eComponentTypes::Player2Controller);
	Player2Controller* controller1 = dynamic_cast<Player2Controller*>(pComp1);
	controller1->Player2           = &Player2;
	controller1->Level             = &level11;
	controller1->Boxes.push_back(&Box1);
	controller1->Boxes.push_back(&Box2);
	controller1->Boxes.push_back(&Box3);
	controller1->Boxes.push_back(&Box4);
	controller1->Boxes.push_back(&Box5);
	controller1->Boxes.push_back(&Box6);
	controller1->Boxes.push_back(&Box7);
	controller1->Boxes.push_back(&Box8);
	controller1->Boxes.push_back(&Box9);
	controller1->Boxes.push_back(&Box10);
	controller1->Boxes.push_back(&Box11);
	controller1->Boxes.push_back(&Box12);
	controller1->Boxes.push_back(&Box13);
	controller1->Boxes.push_back(&Box14);
	controller1->Boxes.push_back(&Box15);
	controller1->Boxes.push_back(&Box16);

	Component*         pCompM  = AddComponentToObject(&Player1, eComponentTypes::Player1BoxMove);
	Component*         pCompM2 = AddComponentToObject(&Player2, eComponentTypes::Player2BoxMove);
	Player1BoxMove* BoxMove    = dynamic_cast<Player1BoxMove*>(pCompM);
	Player2BoxMove* BoxMove1   = dynamic_cast<Player2BoxMove*>(pCompM2);
	BoxMove->Player1           = &Player1;
	BoxMove1->Player2          = &Player2;
	BoxMove->Level             = &level11;
	BoxMove1->Level            = &level11;

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			switch (level11.GetIndex(x, y))
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
	camera.position.Set(150, 200, -20);
	State::m_pCamera = &camera;

	levelSign.SetName("LevelSign");
	levelSign.transform.SetScale(250.f, 50.f);
	levelSign.sprite.LoadImage("texture/LevelSign11.png", m_renderer);
	levelSign.sprite.isHud = true;
	levelSign.transform.position.Set(-425.f, 200.f, 1.f);
	AddObject(&levelSign);
}


void Level11::Update(float dt)
{
	UpdateObjects(dt);

	if (m_input->IsTriggered(SDL_SCANCODE_R))
		m_game->Restart();

	if ((level11.GetIndex(Player1.GetCharacterXIndex(), Player1.GetCharacterYIndex()) ==
		level11.GetIndex(player1Clear.GetClearMagXIndex(), player1Clear.GetClearMagYIndex())) &&
		(level11.GetIndex(Player2.GetCharacterXIndex(), Player2.GetCharacterYIndex()) ==
			level11.GetIndex(player2Clear.GetClearNetXIndex(), player2Clear.GetClearNetYIndex())))
	{
		m_game->SetLevelId(11);
		m_game->Change(LV_ClearScreen);
	}

	// Must be one of the last functions called at the end of State Update
	if (m_input->IsTriggered(SDL_SCANCODE_PAGEDOWN))
	{
		m_game->Change(LV_Level10);
	}
	else if (m_input->IsTriggered(SDL_SCANCODE_PAGEUP))
	{
		m_game->Change(LV_EndingCutscenes);
	}

	Render(dt);
}


void Level11::Close()
{
	// Wrap up state
	ClearBaseState();
	Music.sound.Free();
	level11.InitializeIndex();
}
