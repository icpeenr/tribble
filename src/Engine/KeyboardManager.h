#pragma once

class KeyboardManager
{
private:
	KeyboardManager();
public:
	~KeyboardManager();
public:
	bool IsKeyUp(int key);
	bool IsKeyDown(int key);
	bool IsKeyHeld(int key);
	bool IsKeyPressed(int key);
	bool IsKeyReleased(int key);
public:
	void Update();
private:
	bool m_bCurrentState[GLFW_KEY_LAST];
	bool m_bPreviousState[GLFW_KEY_LAST];
public:
	static KeyboardManager* GetInstance();
private:
	static KeyboardManager* m_pInstance;
};