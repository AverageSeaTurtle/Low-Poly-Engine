#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Display.h"
#include <vector>

class Application
{
public:
	Application();
	~Application();

	void Loop();

	bool Init();

	COLOR::RGB_f backgroud_color;

private:

	void Update();

	void Render();

	GLFWwindow* window;

	std::vector<Display> displays;

};