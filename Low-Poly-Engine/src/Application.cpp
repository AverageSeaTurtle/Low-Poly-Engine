#include "Application.h"

#include <iostream>

Application::Application()
{
	this->window = nullptr;
}

Application::~Application()
{
	glfwTerminate();
}

void Application::Loop()
{
	while (!glfwWindowShouldClose(this->window)) {
		this->Update();
		this->Render();
	}
}

void Application::Update()
{


}

void Application::Render()
{
	/* Render here */
	glClear(GL_COLOR_BUFFER_BIT);

	/* ---- Draw here ---- */
	glBegin(GL_TRIANGLES);

	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.0f, 0.5f);
	glVertex2f(0.5f, -0.5f);

	glEnd();
	/* ------------------- */

	/* Swap front and back buffers */
	glfwSwapBuffers(this->window);

	/* Poll for and process events */
	glfwPollEvents();
}

bool Application::Init()
{
	/* Initialize Glfw */
	if (!glfwInit())
		return false;

	/* Create a windowed mode window and its OpenGL context */
	this->window = glfwCreateWindow(640, 480, "Low-Poly Engine", NULL, NULL);
	if (!this->window)
	{
		glfwTerminate();
		return false;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(this->window);

	/* Initialize Glew (it needs to be initialized before a context)*/
	if (glewInit() != GLEW_OK)
		return false;

	return true;

}
