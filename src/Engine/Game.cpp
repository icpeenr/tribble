#include "Game.h"

Game::Game()
{
	m_fElapsedTime = 0.0f;
	m_bIsExiting = false;
	//m_pWindowManager = WindowManager::GetInstance();
}

Game::~Game()
{
	auto v = Vector2i::Zero;
	//delete m_pWindowManager;
}

void Game::Initialize()
{
	//m_pWindowManager->Initialize();
}

void Game::LoadContent()
{
}

void Game::Update(float elapsedTime)
{
	//m_fElapsedTime = (float)glfwGetTime();

}

void Game::Draw()
{

	//glfwSwapBuffers(m_pWindow);
}

void Game::UnloadContent()
{
}

void Game::Exit()
{
	m_bIsExiting = true;
}

const float Game::GetElapsedTime() const
{
	return m_fElapsedTime;
}

const bool Game::IsExiting() const
{
	return m_bIsExiting;
}
/*
WindowManager* Game::GetWindowManager() const
{
	return m_pWindowManager;
}*/