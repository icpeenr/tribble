#pragma once

#include "Vector2.h"

class Game
{
protected:
	Game();
public:
	virtual ~Game();
protected:
	virtual void			Initialize();
	virtual void			LoadContent();
	virtual void			Update(float elapsedTime);
	virtual void			Draw();
	virtual void			UnloadContent();
	virtual void			Exit();
public:
	const float 			GetElapsedTime() const;
	const bool				IsExiting() const;
	//WindowManager*			GetWindowManager() const;
private:
	float					m_fElapsedTime;
	bool					m_bIsExiting;
	Vector2i				m_oVector;
	//WindowManager*			m_pWindowManager;
};