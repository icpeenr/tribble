#pragma once

#include "Common.h"

class GraphicsDeviceManager
{
private:
	GraphicsDeviceManager();
public:
	~GraphicsDeviceManager();
public:
	static GraphicsDeviceManager*	GetInstance();
public:
	void							Initialize();
	//Viewport						GetViewport() const;
	void							End();
private:
	//bool IsExtensionSupported(const char* extension);
private:
	static GraphicsDeviceManager*	m_pInstance;
	//Viewport						m_oViewport;
};