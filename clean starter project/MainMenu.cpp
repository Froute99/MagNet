/**************************************************************************************
File Name        : MainMenu.cpp
Project name     : MaG+NeT
Primary Author   : Eunjin Hong
Secondary Author : Jihoon Kim
Email	         : chocob0217@gmail.com
Copyright Information :
    "All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/

#include "CommonLevel.h"

const SDL_Color WHITE = { 255, 255, 255, 255 };
const SDL_Color MAROON = { 128, 0, 0, 255 };
const SDL_Color Grey = { 150,150,150,255 };


void MainMenu::Initialize()
{
    State::sCurrentState = this;

    backgroundMusic.LoadMusic("sound/A Himitsu - Adventures [Argofox].mp3");
    m_pBGM = &backgroundMusic;
    if (!backgroundMusic.IsPlaying())
    {
        backgroundMusic.Play();
    }
    backgroundMusic.SetVolume(50);

    background.SetName("Background");
    background.transform.SetScale(m_width, m_height);
    background.sprite.LoadImage("texture/background.png", State::m_renderer);
    background.sprite.color = { 255,255,255,60 };
    AddObject(&background);

    mag.SetName("Mag");
    mag.transform.SetScale(194.75f, 242.f);
    mag.sprite.LoadImage("texture/player1.png", m_renderer);
    mag.transform.position.Set(-350.f, -100.f, 0.f);
    AddObject(&mag);

    net.SetName("Net");
    net.transform.SetScale(194.75f, 242.f);
    net.sprite.LoadImage("texture/player2.png", m_renderer);
    net.transform.position.Set(350.f, -100.f, 0.f);
    AddObject(&net);

    pressEnter.SetName("PressEnter");
    pressEnter.transform.position.Set(0, -280.f, 0);
    pressEnter.transform.SetScale(400.f, 27.f);
    pressEnter.sprite.LoadImage("texture/pressEntertoContinue.png", m_renderer);
    pressEnter.sprite.activeAnimation = true;
    pressEnter.sprite.SetFrame(2);
    pressEnter.sprite.SetSpeed(2.f);
    AddObject(&pressEnter);

    camera.position.Set(0, 0, 0);

    CreateHudSprite(&teamLogo, "TeamLogo", 540.f, -320.f, 197.4f, 69.3f, "texture/TeamLogo_Splash.png", true);
    CreateHudSprite(&gameLogo, "GameLogo", 0.f, 200.f, 1002.3f, 206.57f, "texture/game_logo.png", true);
    CreateHudSprite(&digipenLogo, "DigipenLogo", -525.f, -320.f, 222.36f, 72.2f, "texture/DigipenLogo.png", true);
    CreateHudSprite(&select, "Select", 0.f, 0.f, 360.f, 60.f, "texture/select.png", true);

    CreateStartButton();
    CreateExitButton();
    CreateCreditButton();
    InitializeObjects();
}


void MainMenu::Update(float dt)
{
    UpdateObjects(dt);

    if (m_input->IsTriggered(SDL_SCANCODE_P))
        m_game->Pause();

    if (m_input->IsTriggered(SDL_SCANCODE_DOWN))
    {
        keyPressSound.SetName("KeyPressSound");
        keyPressSound.sound.LoadSound("sound/beep.wav");
        keyPressSound.sound.SetVolume(30);
        keyPressSound.sound.Play();

        if (select.transform.position.y > -200.f)
        {
            select.transform.position.Set(select.transform.position.x, select.transform.position.y -= 100.f, select.transform.position.z);
        }
    }

    if (m_input->IsTriggered(SDL_SCANCODE_UP))
    {
        keyPressSound.SetName("KeyPressSound");
        keyPressSound.sound.LoadSound("sound/beep.wav");
        keyPressSound.sound.SetVolume(30);
        keyPressSound.sound.Play();

        if (select.transform.position.y < 0.f)
        {
            select.transform.position.Set(select.transform.position.x, select.transform.position.y += 100.f, select.transform.position.z);
        }
    }

    if (select.transform.position.y == -100.f)
    {
        exitButton.sprite.Free();
        exitButton.sprite.LoadImage("texture/exit_game2.png", State::m_renderer);
        if (m_input->IsTriggered(SDL_SCANCODE_RETURN))
        {
            m_game->Quit();
        }
    }
    else
    {
        exitButton.sprite.Free();
        exitButton.sprite.LoadImage("texture/exit_game.png", State::m_renderer);
    }

    if (select.transform.position.y == 0.f)
    {
        startButton.sprite.Free();
        startButton.sprite.LoadImage("texture/game_start2.png", State::m_renderer);
        if (m_input->IsTriggered(SDL_SCANCODE_RETURN))
        {
            m_game->Change(LV_OpeningCutscenes);
        }
    }
    else
    {
        startButton.sprite.Free();
        startButton.sprite.LoadImage("texture/game_start.png", State::m_renderer);
    }


    if (select.transform.position.y == -200.f)
    {
        creditButton.sprite.Free();
        creditButton.sprite.LoadImage("texture/credits2.png", State::m_renderer);
        if (m_input->IsTriggered(SDL_SCANCODE_RETURN))
        {
            m_game->Change(LV_Credit1);
        }
    }
    else
    {
        creditButton.sprite.Free();
        creditButton.sprite.LoadImage("texture/credits.png", State::m_renderer);
    }

    Render(dt);
}


void MainMenu::Close()
{
    ClearBaseState();
}


void MainMenu::CreateHudSprite(Object *sprite, const char* name, float positionX, float positionY,
    float scaleX, float scaleY, const char* filePath, bool isVisible)
{
    sprite->SetName(name);
    sprite->transform.position.Set(positionX, positionY, 0);
    sprite->transform.SetScale(scaleX, scaleY);
    sprite->transform.rotation = 0;

    sprite->sprite.LoadImage(filePath, State::m_renderer);
    sprite->sprite.isHud = true;
    sprite->sprite.isVisible = isVisible;
    State::sCurrentState->AddObject(sprite);
}


void MainMenu::CreateStartButton()
{
    startButton.SetName("StartButton");
    startButton.transform.position.Set(0, 0.f, 0.f);
    startButton.transform.SetScale(300.f, 60.f);
    startButton.sprite.LoadImage("texture/game_start.png", State::m_renderer);
    startButton.sprite.isHud = true;
    AddObject(&startButton);
}


void MainMenu::CreateExitButton()
{
    exitButton.SetName("GameExit");
    exitButton.transform.position.Set(0, -100, 0.f);
    exitButton.transform.SetScale(300.f, 60.f);
    exitButton.sprite.LoadImage("texture/exit_game.png", State::m_renderer);
    exitButton.sprite.isHud = true;
    AddObject(&exitButton);
}


void MainMenu::CreateCreditButton()
{
    creditButton.SetName("Credits");
    creditButton.transform.position.Set(0, -200, 0.f);
    creditButton.transform.SetScale(300.f, 60.f);
    creditButton.sprite.LoadImage("texture/credits.png", State::m_renderer);
    creditButton.sprite.isHud = true;
    AddObject(&creditButton);
}


