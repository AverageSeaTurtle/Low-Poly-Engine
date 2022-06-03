#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Application
{
public:
	Application();
	~Application();

	void Loop();

	bool Init();

private:

	void Update();

	void Render();

	GLFWwindow* window;

};