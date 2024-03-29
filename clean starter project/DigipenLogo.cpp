/**************************************************************************************
File Name    : DigipenLogo.cpp
Project name : MaG+NeT
Author	     : Eunjin Hong
Email	     : chocob0217@gmail.com
Copyright Information :
	"All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/

#include "DigipenLogo.h"
#include "CommonLevel.h"

const SDL_Color WHITE = { 255, 255, 255, 255 };

// Derived initialize function
void DigipenLogo::Initialize()
{
	sCurrentState = this;
	m_backgroundColor = WHITE;

	camera.position.Set(0, 0, 0);

	digipenLogo.SetName("digipenLogo");
	digipenLogo.transform.position.Set(0, 0, 0);
	digipenLogo.transform.SetScale(1113.f, 361.f);
	digipenLogo.sprite.LoadImage("texture/DigipenLogo.png", m_renderer);
}
// Derived Update function


void DigipenLogo::Update(float dt)
{
	UpdateObjects(dt);

	static float time = 0;
	static float i = 0;
	time += dt;
	i += dt;

	if (time > 0.8)
	{
		digipenLogo.sprite.color = { 255,255,255, 51 };
		this->AddObject(&digipenLogo);
	}
	if (time > 0.85)
	{
		digipenLogo.sprite.color = { 255,255,255, 102 };
	}
	if (time > 0.9)
	{
		digipenLogo.sprite.color = { 255,255,255, 153 };
	}
	if (time > 0.95)
	{
		digipenLogo.sprite.color = { 255,255,255, 204 };
	}
	if (time > 1)
	{
		digipenLogo.sprite.color = { 255,255,255, 255 };
	}
	if (time > 3)
	{
		digipenLogo.sprite.color = { 255,255,255, 204 };
	}
	if (time > 3.05)
	{
		digipenLogo.sprite.color = { 255,255,255, 153 };
	}
	if (time > 3.1)
	{
		digipenLogo.sprite.color = { 255,255,255, 102 };
	}
	if (time > 3.15)
	{
		digipenLogo.sprite.color = { 255,255,255, 51 };
	}
	if (time > 3.2)
	{
		digipenLogo.sprite.Free();
		this->RemoveObject(&digipenLogo);
	}
	if (time > 3.25)
	{
		m_game->Change(LV_TeamLogo);
	}

	Render(dt);
}


// Derived Close function
void DigipenLogo::Close() { ClearBaseState(); }