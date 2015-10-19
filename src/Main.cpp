#include "Common.h"

#include "KeyboardManager.cpp"

global_variable const uint32 g_windowwidth = 640;
global_variable const uint32 g_windowheight = 480;

int main (int /* argc */, char** /* argv */)
{
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
	bool32 fullscreen = false;

	while(running)
	{
		glClearColor(0.5f, 0.6f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		glfwSwapBuffers(window);
		glfwPollEvents();

		if (glfwWindowShouldClose(window) ||
			glfwGetKey(window, GLFW_KEY_ESCAPE))
			running = false;

		if(glfwGetKey(window, GLFW_KEY_F11))
		{
			fullscreen = !fullscreen;

			GLFWwindow *newWindow;
			if(fullscreen)				
				newWindow = glfwCreateWindow(1024, 600,"Tribble", glfwGetPrimaryMonitor(), window);
			else
				newWindow = glfwCreateWindow(g_windowwidth, g_windowwidth,"Tribble", nullptr, window);
			
			glfwDestroyWindow(window);
			window = newWindow;
			glfwMakeContextCurrent(window);
		}
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return EXIT_SUCCESS;
}