/**************************************************************************************
File Name    : Credit1.cpp
Project name : MaG+NeT
Author	     : Eunjin Hong
Email	     : chocob0217@gmail.com
Copyright Information :
    "All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/

#include "Credit1.h"
#include "CommonLevel.h"

const SDL_Color BLACK = { 0, 0, 0, 255 };


// Derived initialize function
void Credit1::Initialize()
{
    sCurrentState = this;
    m_backgroundColor = BLACK;

    camera.position.Set(0, 0, 0);

    credit1.SetName("Credits1");
    credit1.transform.position.Set(0, 0.f, 0);
    credit1.transform.SetScale(1280.f, 720.f);
    credit1.sprite.LoadImage("texture/credit1.png", m_renderer);

    pressBack.SetName("PressBack");
    pressBack.transform.position.Set(-420.f, 330.f, 0);
    pressBack.transform.SetScale(430.f, 51.f);
    pressBack.sprite.LoadImage("texture/pressBack.png", m_renderer);

    pressSpace.SetName("PressSpace");
    pressSpace.transform.position.Set(360.f, -330.f, 0);
    pressSpace.transform.SetScale(525.f, 39.f);
    pressSpace.sprite.LoadImage("texture/see_next.png", m_renderer);


    this->AddObject(&credit1);
    this->AddObject(&pressBack);
    this->AddObject(&pressSpace);
}


// Derived Update function
void Credit1::Update(float dt)
{
    UpdateObjects(dt);

    if (m_input->IsTriggered(SDL_SCANCODE_SPACE))
    {
		credit1.sprite.Free();
		pressBack.sprite.Free();
        pressSpace.sprite.Free();
        m_game->Change(LV_Credit2);
    }

    Render(dt);
}


// Derived Close function
void Credit1::Close() { ClearBaseState(); }