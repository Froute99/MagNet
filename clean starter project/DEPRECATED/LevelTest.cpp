#include "LevelTest.h"
#include "CommonLevel.h"
#include "CreateObject.h"
#include "Player1Controller.h"
#include "Player2Controller.h"
#include "Player1BoxMove.h"
#include "Player2BoxMove.h"

namespace LevelTestColor
{
	const SDL_Color RED = { 255, 0, 0, 255 };
	const SDL_Color BLUE = { 0, 0, 255, 255 };
	const SDL_Color BLACK = { 0, 0, 0, 255 };
	const SDL_Color WALL_COLOR = { 50, 50, 50, 200 };
	const SDL_Color BOX_COLOR = { 200, 200, 200, 180 };
}

void LevelTest::Initialize()
{
	const int width = 8;
	const int height = 10;

	State::sCurrentState = this;
	for (int i = 0; i < width; i++)
	{
		levelTest.index[i][0] = Index::LEVEL_COMPONENT::WALL;
		levelTest.index[i][height - 1] = Index::LEVEL_COMPONENT::WALL;
	}

	for (int i = 0; i < height; i++)
	{
		levelTest.index[0][i] = Index::LEVEL_COMPONENT::WALL;
		levelTest.index[width - 1][i] = Index::LEVEL_COMPONENT::WALL;
	}

	levelTest.index[5][5] = Index::LEVEL_COMPONENT::MAG;
	Player1.SetCharacterXIndex(5);
	Player1.SetCharacterYIndex(5);
	levelTest.index[4][6] = Index::LEVEL_COMPONENT::NET;
	Player2.SetCharacterXIndex(4);
	Player2.SetCharacterYIndex(6);

	levelTest.index[2][3] = Index::LEVEL_COMPONENT::BOX;
	levelTest.index[2][4] = Index::LEVEL_COMPONENT::BOX;

	levelTest.InitiallizeMapTile(width, height);

	MakeObject(Box1, "Box1", 2, 3);
	Box1.sprite.LoadImage("texture/Box.png", State::m_renderer);
	MakeObject(Box2, "Box2", 2, 4);
	Box2.sprite.LoadImage("texture/Box.png", State::m_renderer);

	Component*         pComp = AddComponentToObject(&Player1, eComponentTypes::Player1Controller);
	Player1Controller* controller = dynamic_cast<Player1Controller*>(pComp);
	controller->Player1 = &Player1;
	controller->Level = &levelTest;
	controller->Boxes.push_back(&Box1);
	controller->Boxes.push_back(&Box2);

	Component*         pComp1 = AddComponentToObject(&Player2, eComponentTypes::Player2Controller);
	Player2Controller* controller1 = dynamic_cast<Player2Controller*>(pComp1);
	controller1->Player2 = &Player2;
	controller1->Level = &levelTest;
	controller1->Boxes.push_back(&Box1);
	controller1->Boxes.push_back(&Box2);

	Component*         pCompM = AddComponentToObject(&Player1, eComponentTypes::Player1BoxMove);
	Component*         pCompM2 = AddComponentToObject(&Player2, eComponentTypes::Player2BoxMove);
	Player1BoxMove* BoxMove = dynamic_cast<Player1BoxMove*>(pCompM);
	Player2BoxMove* BoxMove1 = dynamic_cast<Player2BoxMove*>(pCompM2);
	BoxMove->Player1 = &Player1;
	BoxMove1->Player2 = &Player2;
	BoxMove->Level = &levelTest;
	BoxMove1->Level = &levelTest;

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			switch (levelTest.index[x][y])
			{
			case Index::LEVEL_COMPONENT::WALL:
				CreateWall(float(x), float(y));
				break;
			case Index::LEVEL_COMPONENT::MAG:
				MakeObject(Player1, "Mag", float(x), float(y));
				Player1.sprite.LoadImage("texture/RedDown.png", State::m_renderer);
				break;
			case Index::LEVEL_COMPONENT::NET:
				MakeObject(Player2, "Net", float(x), float(y));
				Player2.sprite.LoadImage("texture/BlueDown.png", State::m_renderer);
				break;
			default:;
			}
		}
	}

	// Set background color
	m_backgroundColor = LevelTestColor::BLACK;
	// Set position of the camera
	camera.position.Set(200, 135, -10);
	State::m_pCamera = &camera;

	mainFont = TTF_OpenFont("font/Default.ttf", 48);

	SetPhysicsWorld({ 0, 0 });

	//SetIntroTexts();
	levelSign.SetName("LevelSign");
	levelSign.transform.SetScale(250.f, 50.f);
	levelSign.sprite.LoadImage("texture/LevelSign1.png", m_renderer);
	levelSign.sprite.isHud = true;
	levelSign.transform.position.Set(-425.f, 200.f, 1.f);
	AddObject(&levelSign);
}

void LevelTest::Update(float dt)
{
	UpdateObjects(dt);

	if (m_input->IsTriggered(SDL_SCANCODE_R))
		m_game->Restart();

	// Must be one of the last functions called at the end of State Update

	UpdatePhysics(dt);
	Render(dt);
}

void LevelTest::Close()
{
	// Wrap up state
	ClearBaseState();
	levelTest.InitializeIndex();

}

void LevelTest::SetIntroTexts()
{
	introTexts[0].transform.position.Set(-425.f, 275.f, 1.f);
	introTexts[0].transform.SetScale(250.f, 50.f);
	introTexts[0].text.font = mainFont;
	introTexts[0].text.SetText("This is a prototype");

	for (auto& object : introTexts)
	{
		object.text.isHud = true;
		AddObject(&object);
	}
}
