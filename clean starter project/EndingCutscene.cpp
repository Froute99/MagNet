/**************************************************************************************
File Name    : EndingCutscene.cpp
Project name : MaG+NeT
Author	     : Eunjin Hong
Email	     : chocob0217@gmail.com
Copyright Information :
    "All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/

#include "EndingCutscene.h"
#include "CommonLevel.h"

const SDL_Color BLACK = { 0, 0, 0, 0 };


// Derived initialize function
void EndingCutscene::Initialize()
{
	sceneNumber = 0;
    sCurrentState = this;
    m_backgroundColor = BLACK;

    camera.position.Set(0, 0, 0);

    cutScene.SetName("cutScene");
    cutScene.transform.position.Set(0, 0, 0);
    cutScene.transform.SetScale(808.f, 330.f);
    cutScene.sprite.LoadImage("texture/cutscenes/cutscene_01.png", m_renderer);

    endingSong.SetName("EndingSong");
    endingSong.sound.LoadSound("sound/Coffee_Stains.mp3");
    endingSong.sound.SetVolume(30);
    endingSong.sound.Play();

    pressEnter.SetName("PressEnter");
    pressEnter.transform.position.Set(600.f, -330.f, 0.f);
    pressEnter.transform.SetScale(526.f, 18.f);
    pressEnter.sprite.LoadImage("texture/pressN.png", m_renderer);
    this->AddObject(&pressEnter);
}


// Derived Update function
void EndingCutscene::Update(float dt)
{
    UpdateObjects(dt);


    if (m_input->IsTriggered(SDL_SCANCODE_RETURN))
    {
        sceneNumber++;
    }

    if (sceneNumber == 1)
    {
		cutScene.sprite.Free();
        cutScene.transform.position.Set(0, 0, 0);
        cutScene.transform.SetScale(668.f, 503.f);
        cutScene.sprite.LoadImage("texture/cutscenes/cutscene_09.png", m_renderer);

        this->AddObject(&cutScene);
    }
    if (sceneNumber == 2)
    {
		cutScene.sprite.Free();
        cutScene.transform.position.Set(0, 0, 0);
        cutScene.sprite.LoadImage("texture/cutscenes/cutscene_10.png", m_renderer);
    }

    if (sceneNumber == 3)
    {
        RemoveObject(&cutScene);
    }

    if (sceneNumber == 4)
    {
		cutScene.sprite.Free();
        cutScene.transform.position.Set(0, 0, 0);
        cutScene.transform.SetScale(925.f, 370.f);
        cutScene.sprite.LoadImage("texture/cutscenes/cutscene_11.png", m_renderer);
        AddObject(&cutScene);
    }

    if (sceneNumber == 5)
    {
        RemoveObject(&cutScene);
    }

    if (sceneNumber == 6)
    {
        m_game->Change(LV_Credit1);
    }

    Render(dt);
}


// Derived Close function
void EndingCutscene::Close()
{
    endingSong.sound.Free();
    ClearBaseState();
}