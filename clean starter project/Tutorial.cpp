/**************************************************************************************
File Name    : Tutorial.cpp
Project name : MaG+NeT
Author	     : Jihoon Kim
Email	     : jihoon1602@gmail.com
Copyright Information :
    "All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/

#include "CommonLevel.h"
#include "CreateObject.h"
#include "Tutorial.h"
#include "Player1BoxMove.h"
#include "Player1Controller.h"
#include "Player2BoxMove.h"
#include "Player2Controller.h"

void Tutorial::Initialize()
{
    Music.SetName("Music");
    Music.sound.LoadSound("sound/nekzlo-storieschillroyaltyfreemusic-Awqs6d9A.mp3");
    Music.sound.SetVolume(100);
    Music.sound.Play();

    const int width = tutorial.GetWidth();
    const int height = tutorial.GetHeight();

    State::sCurrentState = this;

    for (int i = 0; i < width; i++)
    {
        tutorial.SetIndex(i, 0, Index::WALL);
        tutorial.SetIndex(i, height - 1, Index::WALL);
    }

    for (int i = 0; i < height; i++)
    {
        tutorial.SetIndex(0, i, Index::WALL);
        tutorial.SetIndex(width - 1, i, Index::WALL);
    }
    
    Player1.SetCharacterXIndex(4);
    Player1.SetCharacterYIndex(2);
    Player2.SetCharacterXIndex(5);
    Player2.SetCharacterYIndex(2);
    tutorial.SetIndex(Player1.GetCharacterXIndex(), Player1.GetCharacterYIndex(), Index::MAG);
    tutorial.SetIndex(Player2.GetCharacterXIndex(), Player2.GetCharacterYIndex(), Index::NET);
    Player1.SetMovableStatus(Character::Unable);
    Player2.SetMovableStatus(Character::Unable);

    tutorial.InitializeMapTile(width, height);

    tutorial.SetIndex(1, 4, Index::BOX);
    tutorial.SetIndex(2, 4, Index::BOX);
    tutorial.SetIndex(3, 4, Index::BOX);
    tutorial.SetIndex(4, 4, Index::BOX);
    tutorial.SetIndex(5, 4, Index::BOX);
    tutorial.SetIndex(6, 4, Index::BOX);
    tutorial.SetIndex(7, 4, Index::BOX);
    tutorial.SetIndex(8, 4, Index::BOX);

	player1Clear.SetClearMagXIndex(4);
	player1Clear.SetClearMagYIndex(6);
	player2Clear.SetClearNetXIndex(5);
	player2Clear.SetClearNetYIndex(6);
	tutorial.SetIndex(player1Clear.GetClearMagXIndex(), player1Clear.GetClearMagYIndex(), Index::CLEAR_MAG);
	tutorial.SetIndex(player2Clear.GetClearNetXIndex(), player2Clear.GetClearNetYIndex(), Index::CLEAR_NET);
	MakeObject(player1Clear, "MagClear", static_cast<float>(player1Clear.GetClearMagXIndex()), static_cast<float>(player1Clear.GetClearMagYIndex()));
	MakeObject(player2Clear, "NetClear", static_cast<float>(player2Clear.GetClearNetXIndex()), static_cast<float>(player2Clear.GetClearNetYIndex()));

    Component*         pComp      = AddComponentToObject(&Player1, eComponentTypes::Player1Controller);
    Player1Controller* controller = dynamic_cast<Player1Controller*>(pComp);
    controller->Player1           = &Player1;
    controller->Level             = &tutorial;
    controller->Boxes.push_back(&Box1);
    controller->Boxes.push_back(&Box2);
    controller->Boxes.push_back(&Box3);
    controller->Boxes.push_back(&Box4);
    controller->Boxes.push_back(&Box5);
    controller->Boxes.push_back(&Box6);
    controller->Boxes.push_back(&Box7);
    controller->Boxes.push_back(&Box8);

    Component*         pComp1      = AddComponentToObject(&Player2, eComponentTypes::Player2Controller);
    Player2Controller* controller1 = dynamic_cast<Player2Controller*>(pComp1);
    controller1->Player2           = &Player2;
    controller1->Level             = &tutorial;
    controller1->Boxes.push_back(&Box1);
    controller1->Boxes.push_back(&Box2);
    controller1->Boxes.push_back(&Box3);
    controller1->Boxes.push_back(&Box4);
    controller1->Boxes.push_back(&Box5);
    controller1->Boxes.push_back(&Box6);
    controller1->Boxes.push_back(&Box7);
    controller1->Boxes.push_back(&Box8);

    Component*      pCompM   = AddComponentToObject(&Player1, eComponentTypes::Player1BoxMove);
    Component*      pCompM2  = AddComponentToObject(&Player2, eComponentTypes::Player2BoxMove);
    Player1BoxMove* BoxMove  = dynamic_cast<Player1BoxMove*>(pCompM);
    Player2BoxMove* BoxMove1 = dynamic_cast<Player2BoxMove*>(pCompM2);
    BoxMove->Player1         = &Player1;
    BoxMove1->Player2        = &Player2;
    BoxMove->Level           = &tutorial;
    BoxMove1->Level          = &tutorial;

    for (int y = 0; y < tutorial.GetHeight(); y++)
    {
        for (int x = 0; x < tutorial.GetWidth(); x++)
        {
            switch (tutorial.GetIndex(x, y))
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

    MakeObject(Box1, "Box1", 1, 4);
    Box1.sprite.LoadImage("texture/Box.png", State::m_renderer);
    MakeObject(Box2, "Box2", 2, 4);
    Box2.sprite.LoadImage("texture/Box.png", State::m_renderer);
    MakeObject(Box3, "Box3", 3, 4);
    Box3.sprite.LoadImage("texture/Box.png", State::m_renderer);
    MakeObject(Box4, "Box4", 4, 4);
    Box4.sprite.LoadImage("texture/Box.png", State::m_renderer);
    MakeObject(Box5, "Box5", 5, 4);
    Box5.sprite.LoadImage("texture/Box.png", State::m_renderer);
    MakeObject(Box6, "Box6", 6, 4);
    Box6.sprite.LoadImage("texture/Box.png", State::m_renderer);
    MakeObject(Box7, "Box7", 7, 4);
    Box7.sprite.LoadImage("texture/Box.png", State::m_renderer);
    MakeObject(Box8, "Box8", 8, 4);
    Box8.sprite.LoadImage("texture/Box.png", State::m_renderer);

    // Set background color
    m_backgroundColor = MapColor::BLACK;
    // Set position of the camera
    camera.position.Set(200, 135, -10);
    State::m_pCamera = &camera;

    levelSign.SetName("LevelSign");
    levelSign.transform.SetScale(250.f, 50.f);
    levelSign.sprite.LoadImage("texture/LevelSignTuto.png", m_renderer);
    levelSign.sprite.isHud = true;
    levelSign.transform.position.Set(-425.f, 300.f, 1.f);
    AddObject(&levelSign);

    magTuto.SetName("MaGTutorial");
    magTuto.transform.SetScale(250.f, 250.f);
    magTuto.sprite.LoadImage("texture/MaGTuto.png", m_renderer);
    magTuto.sprite.isHud = true;
    magTuto.transform.position.Set(-425.f, 100.f, 1.f);
    AddObject(&magTuto);

    netTuto.SetName("NeTTutorial");
    netTuto.transform.SetScale(250.f, 250.f);
    netTuto.sprite.LoadImage("texture/NeTTuto.png", m_renderer);
    netTuto.sprite.isHud = true;
    netTuto.transform.position.Set(425.f, 100.f, 1.f);
    AddObject(&netTuto);

    resetTuto.SetName("ResetTutorial");
    resetTuto.transform.SetScale(350.f, 100.f);
    resetTuto.sprite.LoadImage("texture/ResetTuto.png", m_renderer);
    resetTuto.sprite.isHud = true;
    resetTuto.transform.position.Set(0.f, -250.f, 1.f);
    AddObject(&resetTuto);

}


void Tutorial::Update(float dt)
{
    UpdateObjects(dt);

    if (m_input->IsTriggered(SDL_SCANCODE_R))
        m_game->Restart();

    if ((tutorial.GetIndex(Player1.GetCharacterXIndex(), Player1.GetCharacterYIndex()) ==
        tutorial.GetIndex(player1Clear.GetClearMagXIndex(), player1Clear.GetClearMagYIndex())) &&
        (tutorial.GetIndex(Player2.GetCharacterXIndex(), Player2.GetCharacterYIndex()) ==
            tutorial.GetIndex(player2Clear.GetClearNetXIndex(), player2Clear.GetClearNetYIndex())))
    {
        m_game->SetLevelId(0);
        m_game->Change(LV_ClearScreen);
    }

    // Must be one of the last functions called at the end of State Update
    if (m_input->IsTriggered(SDL_SCANCODE_PAGEDOWN))
    {
        m_game->Change(LV_MainMenu);
    }
    else if (m_input->IsTriggered(SDL_SCANCODE_PAGEUP))
    {
        m_game->Change(LV_Level1);
    }

    Render(dt);
}


void Tutorial::Close()
{
    // Wrap up state
    ClearBaseState();
    Music.sound.Free();
    tutorial.InitializeIndex();
}