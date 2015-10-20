#pragma once

#include "Common.h"
#include "Size2.h"
#include "Vector2.h"

#define WINDOWMANAGER_DEFAULT_SIZE_WIDTH	640//1280
#define	WINDOWMANAGER_DEFAULT_SIZE_HEIGHT	480//1024
#define WINDOWMANAGER_DEFAULT_TITLE			"Tribble Engine"
#define WINDOWMANAGER_DEFAULT_POSITION_X	0
#define WINDOWMANAGER_DEFAULT_POSITION_Y	0

class WindowManager
{
private:
	WindowManager();
public:
	~WindowManager();
public:
	void Initialize();
	void Resize(Size2i size);
public:
	Vector2i GetPosition();
	Size2i GetSize();
	String GetTitle();
public:
	float GetAspectRatio();
public:
	bool IsOpen();
public:
	void SetTitle(String title);
	void SetPosition(const Vector2i& position);
	void SetSize(Size2i size);
private:
	GLFWwindow*		m_pWindow;
	Vector2i 		m_vPosition;
	Size2i 			m_oSize;
	String 			m_sTitle;
};