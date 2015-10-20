#include "ClientGame.h"

ClientGame::ClientGame()
{
}

ClientGame::~ClientGame()
{
}

ClientGame* ClientGame::GetInstance()
{
	return m_pInstance;
}

void ClientGame::LoadContent()
{
	Game::LoadContent();
}

void ClientGame::Initialize()
{
	Game::Initialize();
}

void ClientGame::Update(float elapsedTime)
{

	Game::Update(elapsedTime);
}

void ClientGame::Draw()
{
	
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Game::Draw();
}

void ClientGame::UnloadContent()
{
	Game::UnloadContent();
}

void ClientGame::Run()
{
	float previousElapsedTime = 0.0f;

	float currentElapsedTime = GetElapsedTime();

	float elapsedTime = 0.0f;

	while(!IsExiting())
	{
		previousElapsedTime = currentElapsedTime;

		currentElapsedTime = GetElapsedTime();

		elapsedTime = currentElapsedTime - previousElapsedTime;

		Update(elapsedTime);

		//Sleep(4);

		Draw();
	}
}

ClientGame* ClientGame::m_pInstance = new ClientGame();