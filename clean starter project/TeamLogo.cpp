/**************************************************************************************
File Name    : TeamLogo.cpp
Project name : MaG+NeT
Author	     : Eunjin Hong
Email	     : chocob0217@gmail.com
Copyright Information :
    "All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/

#include "TeamLogo.h"
#include "CommonLevel.h"

const SDL_Color WHITE = { 255, 255, 255, 255 };


// Derived initialize function
void TeamLogo::Initialize()
{
    Music.SetName("Music");
    Music.sound.LoadSound("sound/Whoosh,Sound Design,Whip By,Airy to Whine,High.wav");
    Music.sound.SetVolume(100);
    Music.sound.Play();


    sCurrentState = this;
    m_backgroundColor = WHITE;

    camera.position.Set(0, 0, 0);

    teamLogo.SetName("teamLogo");
    teamLogo.transform.position.Set(0, 0, 0);
    teamLogo.transform.SetScale(526.4f, 184.8f);
    teamLogo.sprite.LoadImage("texture/TeamLogo_Splash.png", m_renderer);

}


// Derived Update function
void TeamLogo::Update(float dt)
{
    UpdateObjects(dt);

    static float time = 0;
    time += dt;

    if (time > 0.8)
    {
        teamLogo.sprite.color = { 255,255,255, 51 };
        this->AddObject(&teamLogo);
    }
    if (time > 0.85)
    {
        teamLogo.sprite.color = { 255,255,255, 102 };
    }
    if (time > 0.9)
    {
        teamLogo.sprite.color = { 255,255,255, 153 };
    }
    if (time > 0.95)
    {
        teamLogo.sprite.color = { 255,255,255, 204 };
    }
    if (time > 1)
    {
        teamLogo.sprite.color = { 255,255,255, 255 };
    }
    if (time > 3)
    {
        teamLogo.sprite.color = { 255,255,255, 204 };
    }
    if (time > 3.05)
    {
        teamLogo.sprite.color = { 255,255,255, 153 };
    }
    if (time > 3.1)
    {
        teamLogo.sprite.color = { 255,255,255, 102 };
    }
    if (time > 3.15)
    {
        teamLogo.sprite.color = { 255,255,255, 51 };
    }
    if (time > 3.2)
    {
        teamLogo.sprite.Free();
        this->RemoveObject(&teamLogo);
    }
    if (time > 3.5)
    {
        m_game->Change(LV_MainMenu);
    }

    Render(dt);
}


// Derived Close function
void TeamLogo::Close()
{
	Music.sound.Free();
	ClearBaseState();
}