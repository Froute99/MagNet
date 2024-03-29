/**************************************************************************************
File Name    : Game.cpp
Project name : MaG+NeT
Author	     : Jihoon Kim & Multiple
Email	     : jihoon1602@gmail.com
Copyright Information :
    "All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/

#include "Game.h"
#include "engine/StateManager.h"
#include "RegisterComponents.h"
#include "RegisterCommands.h"

Game::Game()
{
    m_stateManager = new StateManager;
}

Game::~Game()
{
    if (m_stateManager) {
        delete m_stateManager;
        m_stateManager = nullptr;
    }
}

/**
 * \brief
 * Initialize game states and window size
 *
 * \return
 * True
 */
bool Game::Initialize()
{

    // Set window size
    State::m_width = SCREEN_WIDTH, State::m_height = SCREEN_HEIGHT;

    // Set state ids
    mainMenu.SetId(LV_MainMenu);
    tutorial.SetId(LV_Tutorial);
    level1.SetId(LV_Level1);
    level2.SetId(LV_Level2);
    level3.SetId(LV_Level3);
    level4.SetId(LV_Level4);
    level5.SetId(LV_Level5);
    level6.SetId(LV_Level6);
    level7.SetId(LV_Level7);
    level8.SetId(LV_Level8);
    level9.SetId(LV_Level9);
    level10.SetId(LV_Level10);
    level11.SetId(LV_Level11);
    pauseLevel.SetId(LV_Pause);
    levelClearScreen.SetId(LV_ClearScreen);

    digipenLogo.SetId(LV_DigipenLogo);
    teamLogo.SetId(LV_TeamLogo);
    credit1.SetId(LV_Credit1);
    credit2.SetId(LV_Credit2);
    openingCutscene.SetId(LV_OpeningCutscenes);
    endingCutscene.SetId(LV_EndingCutscenes);

    // Register components
    RegisterComponents();
    // Register commands
    RegisterCommands();

    // Register states
    RegisterState(&mainMenu);
    RegisterState(&tutorial);
    RegisterState(&level1);
    RegisterState(&level2);
    RegisterState(&level3);
    RegisterState(&level4);
    RegisterState(&level5);
    RegisterState(&level6);
    RegisterState(&level7);
    RegisterState(&level8);
    RegisterState(&level9);
    RegisterState(&level10);
    RegisterState(&level11);
    RegisterState(&levelClearScreen);
    RegisterState(&digipenLogo);
    RegisterState(&teamLogo);
    RegisterState(&credit1);
    RegisterState(&credit2);
    RegisterState(&openingCutscene);
    RegisterState(&endingCutscene);


    // Register pause state
    RegisterPauseState(&pauseLevel);

    // Set starting state
    SetFirstState(&digipenLogo);

    // Initlialize current state
    GetCurrentState()->Initialize();

    return true;
}

/**
 * \brief
 * Update state manager
 *
 * \param dt
 * Delta time
 */
void Game::Update(float dt)
{
    StateManager::SetWindowSize(m_width, m_height);
    m_stateManager->Update(dt);
}

/**
* \brief
* Wrap all state stacks up
*/
void Game::Close()
{
    // Unregister components
    UnregisterComponents();
    // Unregister commands
    UnregisterCommands();

    m_stateManager->Close();
}

/**
* \brief
* Set a state as a pause state
*
* \param state
* Address of state to set as the pause state
*/
void Game::RegisterPauseState(State* state)
{
    m_stateManager->RegisterPauseState(state);
}

/**
* \brief
* Stop updating current state and move to pause state
*/
void Game::Pause()
{
    m_stateManager->Pause();
}

/**
* \brief
* Close pause state and move back to last state
*/
void Game::Resume()
{
    m_stateManager->Resume();
}

/**
* \brief
* Restart current state
*/
void Game::Restart()
{
    m_stateManager->Restart();
}

/**
* \brief
* Add a state
*
* \param state
* Address of state to add
*/
void Game::RegisterState(State* state)
{
    m_stateManager->RegisterState(state);
}

/**
* \brief
* Set a state to starting point
*
* \param state
* Address of state to set as the first state
*/
void Game::SetFirstState(State* state)
{
    m_stateManager->SetFirstState(state);
}

/**
* \brief
* Return the address of the current state
*
* \return m_stack.top()
*/
State* Game::GetCurrentState()
{
    return m_stateManager->GetCurrentState();
}

/**
* \brief
* Set game state manager to shutdown
*/
void Game::Quit()
{
    m_stateManager->Quit();
}

/**
* \brief
* Change current state to other state
*
* \param stateId
* Id of state to change
*/
void Game::Change(unsigned stateId)
{
    m_stateManager->Change(stateId);
}


/**
 * \brief
 * Check either if the app gets ready to quit
 *
 * \return m_stateManager->IsQuit()
 */
bool Game::IsQuit()
{
    return m_stateManager->IsQuit();
}
