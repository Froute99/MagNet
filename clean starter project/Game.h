/******************************************************************************/
/*!
\file   Game.h
\author David Ly and Juyong Jeong
\par    email: dly\@digipen.edu
\par    GAM150 demo
\par	v0
\date   2018/03/11

Game will only handle the changes of the game states (Level switching)
ie. Main Menu, Levels, Pause, etc.
No game play logic should be added here.
*/
/******************************************************************************/
#pragma once

// Level headers
#include "MainMenu.h"
#include "PauseState.h"
#include "LevelClearScreen.h"
#include "DigipenLogo.h"
#include "TeamLogo.h"
#include "OpeningCutscene.h"
#include "EndingCutscene.h"
#include "Credit1.h"
#include "Credit2.h"
#include "Tutorial.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "Level4.h"
#include "level5.h"
#include "level6.h"
#include "level7.h"
#include "level8.h"
#include "level9.h"
#include "level10.h"
#include "level11.h"
//This is the list of levels the game has. When adding a new level(state)
//add it to this list. They are tagged with LV_ to enable better autocomplete 
typedef enum
{
    LV_MainMenu = 0,
    LV_Tutorial,
    LV_Level1,
    LV_Level2,
    LV_Level3,
    LV_Level4,
    LV_Level5,
    LV_Level6,
    LV_Level7,
    LV_Level8,
    LV_Level9,
    LV_Level10,
    LV_Level11,
    LV_ClearScreen,

    LV_DigipenLogo,
    LV_TeamLogo,
    LV_OpeningCutscenes,
    LV_EndingCutscenes,
    LV_Credit1,
    LV_Credit2,

    LV_Pause,
    //etc.

    LV_NUM_LEVELS

}Level_ID;

class StateManager;

class Game
{
    friend class Application;

    StateManager *m_stateManager = nullptr;

public:
    Game();
    ~Game();

    void	RegisterState(State* state);
    void	SetFirstState(State* state);
    State*	GetCurrentState();

    void	Quit();
    void	Change(unsigned stateId);

    bool	Initialize();
    void	Update(float dt);
    void	Close();

    void	RegisterPauseState(State *state);
    void	Pause();
    void	Resume();
    void	Restart();
    bool	IsQuit();

    int     GetLevelId() { return levelId; };
    void    SetLevelId(int id) { levelId = id; };

private:
    // All the level(state) declarations are here
    MainMenu	mainMenu;
    Tutorial    tutorial;
    Level1      level1;
    Level2      level2;
    Level3      level3;
    Level4      level4;
    Level5      level5;
    Level6      level6;
    Level7      level7;
    Level8      level8;
    Level9      level9;
    Level10     level10;
    Level11     level11;

    PauseState	     pauseLevel;
    LevelClearScreen levelClearScreen;
    
    DigipenLogo      digipenLogo;
    TeamLogo         teamLogo;
    Credit1          credit1;
    Credit2          credit2;
    OpeningCutscene  openingCutscene;
    EndingCutscene endingCutscene;

    int levelId = 0;

public:

    static constexpr int SCREEN_WIDTH = 1280, SCREEN_HEIGHT = 720;
    int	m_width = 0, m_height = 0;

    Game(const Game&) = delete;
    Game(Game&&) = delete;
    Game& operator=(const Game&) = delete;
    Game& operator=(Game&&) = delete;

};