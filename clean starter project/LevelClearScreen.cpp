/**************************************************************************************
File Name    : LevelClearScreen.cpp
Project name : MaG+NeT
Author	     : Eunjin Hong
Email	     : chocob0217@gmail.com
Copyright Information :
    "All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/

#include "LevelClearScreen.h"
#include "CommonLevel.h"

const SDL_Color BLACK = {0, 0, 0, 255};

// Derived initialize function
void LevelClearScreen::Initialize()
{
    sCurrentState     = this;
    m_backgroundColor = BLACK;

    camera.position.Set(0, 0, 0);

    clearMusic.SetName("Clear");
    clearMusic.sound.LoadSound("sound/nightclub_audience_applause_cheers_07.wav");
    clearMusic.sound.SetVolume(30);
    clearMusic.sound.Play();

    magVictory.SetName("magVictory");
    magVictory.transform.position.Set(-100, 0, 0);
    magVictory.transform.SetScale(128.f, 128.f);
    magVictory.sprite.LoadImage("texture/RedWin.png", m_renderer);
    magVictory.sprite.activeAnimation = true;
    magVictory.sprite.SetFrame(2);
    magVictory.sprite.SetSpeed(3.f);
    magVictory.sprite.SetFrame(2);
    magVictory.sprite.SetSpeed(3.f);

    netVictory.SetName("netVictory");
    netVictory.transform.position.Set(100, 0, 0);
    netVictory.transform.SetScale(128.f, 128.f);
    netVictory.sprite.LoadImage("texture/BlueWin.png", m_renderer);
    netVictory.sprite.activeAnimation = true;
    netVictory.sprite.SetFrame(2);
    netVictory.sprite.SetSpeed(3.f);

    levelClear.SetName("levelClear");
    levelClear.transform.position.Set(0, 200, 0);
    levelClear.transform.SetScale(694.f, 96.f);
    levelClear.sprite.LoadImage("texture/LevelClear.png", m_renderer);

    pressN.SetName("pressN");
    pressN.transform.position.Set(0, -150, 0);
    pressN.transform.SetScale(526.f, 36.f);
    pressN.sprite.LoadImage("texture/pressN.png", m_renderer);
    pressN.sprite.activeAnimation = true;
    pressN.sprite.SetFrame(2);
    pressN.sprite.SetSpeed(2.f);


    this->AddObject(&magVictory);
    this->AddObject(&netVictory);
    this->AddObject(&levelClear);
    this->AddObject(&pressN);
}
// Derived Update function
void LevelClearScreen::Update(float dt)
{
    UpdateObjects(dt);

    if (m_input->IsTriggered(SDL_SCANCODE_RETURN))
    {
        clearMusic.sound.Free();
        
        if (m_game->GetLevelId() == 0)
        {
            m_game->Change(LV_Level1);
        }
        if (m_game->GetLevelId() == 1)
        {
            m_game->Change(LV_Level2);
        }
        if (m_game->GetLevelId() == 2)
        {
            m_game->Change(LV_Level3);
        }
        else if (m_game->GetLevelId() == 3)
        {
            m_game->Change(LV_Level4);
        }
        else if (m_game->GetLevelId() == 4)
        {
            m_game->Change(LV_Level5);
        }
        else if (m_game->GetLevelId() == 5)
        {
            m_game->Change(LV_Level6);
        }
        else if (m_game->GetLevelId() == 6)
        {
            m_game->Change(LV_Level7);
        }
        else if (m_game->GetLevelId() == 7)
        {
            m_game->Change(LV_Level8);
        }
        else if (m_game->GetLevelId() == 8)
        {
            m_game->Change(LV_Level9);
        }
        else if (m_game->GetLevelId() == 9)
        {
            m_game->Change(LV_Level10);
        }
        else if (m_game->GetLevelId() == 10)
        {
            m_game->Change(LV_Level11);
        }
        else if (m_game->GetLevelId() == 11)
        {
            m_game->Change(LV_EndingCutscenes);
        }
    }

    UpdatePhysics(dt);
    Render(dt);
}
// Derived Close function
void LevelClearScreen::Close() { ClearBaseState(); }