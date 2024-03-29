/**************************************************************************************
File Name    : Level1.cpp
Project name : MaG+NeT
Author	     : Junghak Kim
Email	     : dbh99619@gmail.com
Copyright Information :
    "All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/

#include "CommonLevel.h"
#include "CreateObject.h"
#include "Level1.h"
#include "Player1BoxMove.h"
#include "Player1Controller.h"
#include "Player2BoxMove.h"
#include "Player2Controller.h"

void Level1::Initialize()
{
    Music.SetName("Music");
    Music.sound.LoadSound("sound/nekzlo-storieschillroyaltyfreemusic-Awqs6d9A.mp3");
    Music.sound.SetVolume(100);
    Music.sound.Play();

    const int width      = level1.GetWidth();
    const int height     = level1.GetHeight();

    State::sCurrentState = this;

    for (int i = 0; i < width; i++)
    {
		level1.SetIndex(i, 0, Index::WALL);
		level1.SetIndex(i, height - 1, Index::WALL);
    }
    for (int i = 0; i < height; i++)
    {
		level1.SetIndex(0, i, Index::WALL);
		level1.SetIndex(width - 1, i, Index::WALL);
    }
	level1.SetIndex(1, 6, Index::WALL);
	level1.SetIndex(2, 6, Index::WALL);
	level1.SetIndex(3, 6, Index::WALL);
	level1.SetIndex(6, 6, Index::WALL);
	level1.SetIndex(7, 6, Index::WALL);
	level1.SetIndex(8, 6, Index::WALL);
	level1.SetIndex(4, 1, Index::WALL);
	level1.SetIndex(4, 2, Index::WALL);
	level1.SetIndex(4, 3, Index::WALL);
	level1.SetIndex(4, 4, Index::WALL);
	level1.SetIndex(5, 1, Index::WALL);
	level1.SetIndex(5, 2, Index::WALL);
	level1.SetIndex(5, 3, Index::WALL);
	level1.SetIndex(5, 4, Index::WALL);
	level1.SetIndex(3, 4, Index::WALL);
	level1.SetIndex(6, 4, Index::WALL);
	level1.SetIndex(1, 4, Index::WALL);
	level1.SetIndex(8, 4, Index::WALL);

    Player1.SetCharacterXIndex(2);
    Player1.SetCharacterYIndex(2);
    Player2.SetCharacterXIndex(7);
    Player2.SetCharacterYIndex(2);
    level1.SetIndex(Player1.GetCharacterXIndex(), Player1.GetCharacterYIndex(), Index::MAG);
    level1.SetIndex(Player2.GetCharacterXIndex(), Player2.GetCharacterYIndex(), Index::NET);
    Player1.SetMovableStatus(Character::Unable);
    Player2.SetMovableStatus(Character::Unable);

    level1.InitializeMapTile(width, height);

	level1.SetIndex(2, 3, Index::BOX);
	level1.SetIndex(7, 3, Index::BOX);

    player1Clear.SetClearMagXIndex(4);
    player1Clear.SetClearMagYIndex(6);
    player2Clear.SetClearNetXIndex(5);
    player2Clear.SetClearNetYIndex(6);
    level1.SetIndex(player1Clear.GetClearMagXIndex(), player1Clear.GetClearMagYIndex(), Index::CLEAR_MAG);
    level1.SetIndex(player2Clear.GetClearNetXIndex(), player2Clear.GetClearNetYIndex(), Index::CLEAR_NET);
    MakeObject(player1Clear, "MagClear", static_cast<float>(player1Clear.GetClearMagXIndex()), static_cast<float>(player1Clear.GetClearMagYIndex()));
    MakeObject(player2Clear, "NetClear", static_cast<float>(player2Clear.GetClearNetXIndex()), static_cast<float>(player2Clear.GetClearNetYIndex()));

    Component*         pComp      = AddComponentToObject(&Player1, eComponentTypes::Player1Controller);
    Player1Controller* controller = dynamic_cast<Player1Controller*>(pComp);
    controller->Player1           = &Player1;
    controller->Level             = &level1;
    controller->Boxes.push_back(&Box1);
    controller->Boxes.push_back(&Box2);

    Component*         pComp1      = AddComponentToObject(&Player2, eComponentTypes::Player2Controller);
    Player2Controller* controller1 = dynamic_cast<Player2Controller*>(pComp1);
    controller1->Player2           = &Player2;
    controller1->Level             = &level1;
    controller1->Boxes.push_back(&Box1);
    controller1->Boxes.push_back(&Box2);

    Component*      pCompM   = AddComponentToObject(&Player1, eComponentTypes::Player1BoxMove);
    Component*      pCompM2  = AddComponentToObject(&Player2, eComponentTypes::Player2BoxMove);
    Player1BoxMove* BoxMove  = dynamic_cast<Player1BoxMove*>(pCompM);
    Player2BoxMove* BoxMove1 = dynamic_cast<Player2BoxMove*>(pCompM2);
    BoxMove->Player1         = &Player1;
    BoxMove1->Player2        = &Player2;
    BoxMove->Level = &level1;
    BoxMove1->Level = &level1;

    for (int y = 0; y < level1.GetHeight(); y++)
    {
        for (int x = 0; x < level1.GetWidth(); x++)
        {
            switch (level1.GetIndex(x, y))
            {
                case Index::LEVEL_COMPONENT::WALL:
                    CreateWall(float(x), float(y));
                    break;
                case Index::LEVEL_COMPONENT::MAG:
                    MakeObject(Player1, "Mag", float(x), float(y));
					Player1.sprite.Free();
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

    MakeObject(Box1, "Box1", 2, 3);
    Box1.sprite.LoadImage("texture/Box.png", State::m_renderer);
    MakeObject(Box2, "Box2", 7, 3);
    Box2.sprite.LoadImage("texture/Box.png", State::m_renderer);
    // Set background color
    m_backgroundColor = MapColor::BLACK;
    // Set position of the camera
    camera.position.Set(200, 135, -10);
    State::m_pCamera = &camera;
   
    levelSign.SetName("LevelSign");
    levelSign.transform.SetScale(250.f, 50.f);
    levelSign.sprite.LoadImage("texture/LevelSign1.png", m_renderer);
    levelSign.sprite.isHud = true;
    levelSign.transform.position.Set(-425.f, 200.f, 1.f);
    AddObject(&levelSign);
}


void Level1::Update(float dt)
{
    UpdateObjects(dt);

    if (m_input->IsTriggered(SDL_SCANCODE_R))
        m_game->Restart();

    if ((level1.GetIndex(Player1.GetCharacterXIndex(), Player1.GetCharacterYIndex()) == 
		 level1.GetIndex(player1Clear.GetClearMagXIndex(), player1Clear.GetClearMagYIndex())) && 
		(level1.GetIndex(Player2.GetCharacterXIndex(), Player2.GetCharacterYIndex()) == 
		 level1.GetIndex(player2Clear.GetClearNetXIndex(), player2Clear.GetClearNetYIndex())))
    {
        m_game->SetLevelId(1);
        m_game->Change(LV_ClearScreen);
    }
    // Must be one of the last functions called at the end of State Update
    if (m_input->IsTriggered(SDL_SCANCODE_PAGEDOWN))
    {
        m_game->Change(LV_Tutorial);
    }
    else if (m_input->IsTriggered(SDL_SCANCODE_PAGEUP))
	{
        m_game->Change(LV_Level2);
	}

    Render(dt);
}


void Level1::Close()
{
    // Wrap up state
    ClearBaseState();
    Music.sound.Free();
    level1.InitializeIndex();
}
