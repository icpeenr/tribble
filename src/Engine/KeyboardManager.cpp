#include "Common.h"
#include "KeyboardManager.h"
#include <memory.h> // memset and memcpy
#include <iostream> // debug

KeyboardManager::KeyboardManager()
{
	memset(m_bCurrentState, 0, GLFW_KEY_LAST);
}

KeyboardManager::~KeyboardManager()
{
}

bool KeyboardManager::IsKeyDown(int key)
{
	return m_bCurrentState[key];
}

bool KeyboardManager::IsKeyUp(int key)
{
	return !m_bCurrentState[key];
}

bool KeyboardManager::IsKeyHeld(int key)
{
	return m_bCurrentState[key] && m_bPreviousState[key];
}

bool KeyboardManager::IsKeyPressed(int key)
{
	return m_bCurrentState[key] && !m_bPreviousState[key];
}

bool KeyboardManager::IsKeyReleased(int key)
{
	return !m_bCurrentState[key] && m_bPreviousState[key];
}

void KeyboardManager::Update()
{
	memcpy(m_bPreviousState, m_bCurrentState, GLFW_KEY_LAST);
/*
	for(int a = 0; a < GLFW_KEY_LAST; a++)
	{
		m_bCurrentState[a] = glfwGetKey(a) == GL_TRUE ? true : false;

		if(m_bCurrentState[a])
		{
			m_bCurrentState[a] = true;
		}
	}*/
	}

	KeyboardManager* KeyboardManager::GetInstance()
	{
		if(m_pInstance == NULL)
		{
			m_pInstance = new KeyboardManager();
		}

		return m_pInstance;
	}

	KeyboardManager* KeyboardManager::m_pInstance = NULL;