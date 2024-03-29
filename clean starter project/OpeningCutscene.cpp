/**************************************************************************************
File Name    : OpeningCutscene.cpp
Project name :  MaG+NeT
Author	     :  Eunjin Hong
Email	     :  chocob0217@gmail.com
Copyright Information :
	"All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/


#include "OpeningCutscene.h"
#include "CommonLevel.h"

const SDL_Color BLACK = { 0, 0, 0, 0 };

// Derived initialize function
void OpeningCutscene::Initialize()
{
	sceneNumber = 0;
	isSoundFirstTime = true;
	sCurrentState = this;
	m_backgroundColor = BLACK;

	camera.position.Set(0, 0, 0);

	cutScene.SetName("cutScene");
	cutScene.transform.position.Set(0, 0, 0);
	cutScene.transform.SetScale(808.f, 330.f);

	pressEnter.SetName("PressEnter");
	pressEnter.transform.position.Set(600.f, -330.f, 0.f);
	pressEnter.transform.SetScale(526.f, 18.f);
	pressEnter.sprite.LoadImage("texture/pressN.png", m_renderer);

	this->AddObject(&pressEnter);
}


// Derived Update function
void OpeningCutscene::Update(float dt)
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
		cutScene.transform.SetScale(808.f, 330.f);
		cutScene.sprite.LoadImage("texture/cutscenes/cutscene_01.png", m_renderer);
		AddObject(&cutScene);
	}

	if (sceneNumber == 2)
	{
		if (isSoundFirstTime)
		{
			thunderSound.SetName("ThunderSound");
			thunderSound.sound.LoadSound("sound/Heavy Magical Explosion_SI 03.wav");
			thunderSound.sound.SetVolume(50);
			thunderSound.sound.Play();
			isSoundFirstTime = false;
		}
		cutScene.sprite.Free();
		cutScene.transform.position.Set(0, 0, 0);
		cutScene.transform.SetScale(854.f, 579.f);
		cutScene.sprite.LoadImage("texture/cutscenes/cutscene_02.png", m_renderer);
	}

	if (sceneNumber == 3)
	{
		thunderSound.sound.Free();

		cutScene.sprite.Free();
		cutScene.transform.position.Set(0, 0, 0);
		cutScene.sprite.LoadImage("texture/cutscenes/cutscene_03.png", m_renderer);
	}

	if (sceneNumber == 4)
	{
		cutScene.sprite.Free();
		cutScene.transform.position.Set(0, 0, 0);
		cutScene.sprite.LoadImage("texture/cutscenes/cutscene_04.png", m_renderer);
	}

	if (sceneNumber == 5)
	{
		cutScene.sprite.Free();
		cutScene.transform.SetScale(585.f, 646.f);
		cutScene.transform.position.Set(0, 0, 0);
		cutScene.sprite.LoadImage("texture/cutscenes/cutscene_05.png", m_renderer);
	}


	if (sceneNumber == 6)
	{
		cutScene.sprite.Free();
		cutScene.transform.position.Set(0, 0, 0);
		cutScene.sprite.LoadImage("texture/cutscenes/cutscene_06.png", m_renderer);
	}

	if (sceneNumber == 7)
	{
		cutScene.sprite.Free();
		cutScene.transform.position.Set(0, 0, 0);
		cutScene.sprite.LoadImage("texture/cutscenes/cutscene_07.png", m_renderer);
	}

	if (sceneNumber == 8)
	{
		cutScene.sprite.Free();
		cutScene.transform.position.Set(0, 0, 0);
		cutScene.transform.SetScale(920.f, 564.f);
		cutScene.sprite.LoadImage("texture/cutscenes/cutscene_08.png", m_renderer);
	}

	if (sceneNumber == 9)
	{
		cutScene.sprite.Free();
		m_game->Change(LV_Tutorial);
	}


	Render(dt);
}


// Derived Close function
void OpeningCutscene::Close() { ClearBaseState(); }