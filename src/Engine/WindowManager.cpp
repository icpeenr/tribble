#include "WindowManager.h"

WindowManager::WindowManager()
{
}

WindowManager::~WindowManager()
{
}

void WindowManager::Initialize()
{
	glfwInit();
/*
	glfwOpenWindowHint(GLFW_REFRESH_RATE, 0);
	glfwOpenWindowHint(GLFW_ACCUM_RED_BITS, 8);
	glfwOpenWindowHint(GLFW_ACCUM_GREEN_BITS, 8);
	glfwOpenWindowHint(GLFW_ACCUM_BLUE_BITS, 8);
	glfwOpenWindowHint(GLFW_ACCUM_ALPHA_BITS, 8);
	glfwOpenWindowHint(GLFW_AUX_BUFFERS, 0);
	glfwOpenWindowHint(GLFW_STEREO, GL_FALSE);
	glfwOpenWindowHint(GLFW_WINDOW_NO_RESIZE, GL_FALSE);
	glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 8);
	glfwOpenWindow((int)m_oSize.Width, (int)m_oSize.Height, 8, 8, 8, 8, 8, 8, GLFW_WINDOW);

	glfwSwapInterval(1);

	SetPosition(Vector2i::Zero);
	SetSize(m_oSize);
	SetTitle(m_sTitle);*/
}

Vector2i WindowManager::GetPosition()
{
	// TODO
	return Vector2i::Zero;
}

void WindowManager::SetPosition(const Vector2i& position)
{
	//glfwSetWindowPos((int)position.X, (int)position.Y);
}

void WindowManager::SetSize(Size2i size)
{
	//glfwSetWindowSize((int)size.Width, (int)size.Height);
}

void WindowManager::SetTitle(String title)
{
	//glfwSetWindowTitle(title.c_str());
}

bool WindowManager::IsOpen()
{
	//return glfwGetWindowParam(GLFW_OPENED) == GL_TRUE;
	return false;
}

float WindowManager::GetAspectRatio()
{
	return (float)m_oSize.Width / (float)m_oSize.Height;
}

Size2i WindowManager::GetSize()
{
	return m_oSize;
}

//Size2i WindowManager::m_oSize = Size2i(WINDOWMANAGER_DEFAULT_SIZE_WIDTH, WINDOWMANAGER_DEFAULT_SIZE_HEIGHT);
//String WindowManager::m_sTitle = WINDOWMANAGER_DEFAULT_TITLE;
//Vector2i WindowManager::m_vPosition = Vector2i(WINDOWMANAGER_DEFAULT_POSITION_X, WINDOWMANAGER_DEFAULT_POSITION_Y);
