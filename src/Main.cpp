#include "Common.h"

//TODO: Include header - See CMakeFile ...  maybe
#include "ClientGame.cpp"

global_variable const uint32 g_windowwidth = 640;
global_variable const uint32 g_windowheight = 480;

int main (int /* argc */, char** /* argv */)
{

	//auto v = Vector2<int>::Zero;


	ClientGame* game = ClientGame::GetInstance();

	game->Initialize();
	game->LoadContent();
	//game->Run();
	game->UnloadContent();

	delete game;


	GLFWwindow* window;

	if(!glfwInit())
		return EXIT_FAILURE;

	window = glfwCreateWindow(g_windowwidth, g_windowheight, "Tribble", nullptr, nullptr);
	if(!window)
	{
		glfwTerminate();
		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);

	bool32 running = true;
	while(running)
	{
		glClearColor(0.5f, 0.6f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		glfwSwapBuffers(window);
		glfwPollEvents();

		if (glfwWindowShouldClose(window) ||
			glfwGetKey(window, GLFW_KEY_ESCAPE))
			running = false;
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return EXIT_SUCCESS;
}