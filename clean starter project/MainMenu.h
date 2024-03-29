/**************************************************************************************
File Name        : MainMenu.h
Project name     : MaG+NeT
Primary Author   : Eunjin Hong
Secondary Author : Jihoon Kim
Email	         : chocob0217@gmail.com
Copyright Information :
    "All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/

#pragma once
#include "engine\State.h"
#include "engine\Object.h"

class MainMenu : public State
{
	friend class Game;

protected:
	MainMenu() : State() {};
	~MainMenu() override {};
	// Derived initialize function
	void Initialize() override;
	// Derived Update function
	void Update(float dt) override;
	// Derived Close function
	void Close() override;

private:
    Object background;
	Object teamLogo;
	Object gameLogo;
	Object digipenLogo;
	Object startButton;
	Object exitButton;
    Object creditButton;
    Object mag;
    Object net;
    Object select;
    Object pressEnter;
    Object keyPressSound;

	void CreateHudSprite(Object *sprite, const char* name, float positionX, float positionY,
		float scaleX, float scaleY, const char* filePath, bool isVisible);
	void CreateStartButton();
	void CreateExitButton();
    void CreateCreditButton();
};

