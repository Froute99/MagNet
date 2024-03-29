/**************************************************************************************
File Name    : Credit2.cpp
Project name : MaG+NeT
Author	     : Eunjin Hong
Email	     : chocob0217@gmail.com
Copyright Information :
    "All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/

#include "Credit2.h"
#include "CommonLevel.h"

const SDL_Color BLACK = { 0, 0, 0, 255 };


// Derived initialize function
void Credit2::Initialize()
{
    sCurrentState = this;
    m_backgroundColor = BLACK;

    camera.position.Set(0, 0, 0);

    credit2.SetName("Credits2");
    credit2.transform.position.Set(0, 0.f, 0);
    credit2.transform.SetScale(1280.f, 720.f);
    credit2.sprite.LoadImage("texture/credit2.png", m_renderer);

    pressBack.SetName("PressBack");
    pressBack.transform.position.Set(-420.f, 330.f, 0);
    pressBack.transform.SetScale(430.f, 51.f);
    pressBack.sprite.LoadImage("texture/pressBack.png", m_renderer);

    this->AddObject(&credit2);
    this->AddObject(&pressBack);
}


// Derived Update function
void Credit2::Update(float dt)
{
    UpdateObjects(dt);

    if (m_input->IsTriggered(SDL_SCANCODE_BACKSPACE))
    {
        credit2.sprite.Free();
		pressBack.sprite.Free();
        m_game->Change(LV_MainMenu);
    }

    Render(dt);
}


// Derived Close function
void Credit2::Close() { ClearBaseState(); }