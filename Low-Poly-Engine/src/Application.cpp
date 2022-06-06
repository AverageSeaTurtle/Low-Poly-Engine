#include "Application.h"

#include <iostream>
#include "Shader.h"

Application::Application(int window_width, int window_height, std::string title)
	: window_width(window_width), window_height(window_height), title(title), window(nullptr)
{

}

Application::~Application()
{
	glfwTerminate();
}

void Application::Loop()
{
	displays.push_back(
		Display(0, 0, GetWindowWidth() / 2, GetWindowHeight() / 2));

	displays.push_back(
		Display(GetWindowWidth() / 2, GetWindowHeight() / 2, GetWindowWidth() / 2, GetWindowHeight() / 2));

	displays.push_back(
		Display(GetWindowWidth() / 2, 0, GetWindowWidth() / 2, GetWindowHeight() / 2));

	displays.push_back(
		Display(0, GetWindowHeight() / 2, GetWindowWidth() / 2, GetWindowHeight() / 2));

	/* Set up Basic Shader */
	SHADER::ShaderProgramSource source = SHADER::ParseShader("res/shaders/Basic.shader");
	unsigned int shader = SHADER::CreateShader(source.VertexSource, source.FragmentSource);
	glUseProgram(shader);

	//int shader_color = glGetUniformLocation(shader, "u_Color");

	while (!glfwWindowShouldClose(this->window)) {
		this->Update();
		this->Render();
	}

	glDeleteProgram(shader);
}

void Application::Update()
{


}

void Application::Render()
{
	/* Render here */
	glClear(GL_COLOR_BUFFER_BIT);
	//glClearColor(background_color);

	for (auto& d : displays) {
		d.SetDisplay();

		/* ---- Draw here ---- */
		glBegin(GL_TRIANGLES);

		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);

		glEnd();
		/* ------------------- */

	}

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
	this->window = glfwCreateWindow(window_width, window_height, title.c_str(), NULL, NULL);
	if (!this->window)
	{
		glfwTerminate();
		return false;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(this->window);

	glfwSwapInterval(1);

	/* Initialize Glew (it needs to be initialized before a context)*/
	if (glewInit() != GLEW_OK)
		return false;

	return true;

}

void Application::SetBackgroundColor(const COLOR::RGB_f& color)
{
	background_color = color;
}

const COLOR::RGB_f Application::GetBackgroundColor() const
{
	return background_color;
}
