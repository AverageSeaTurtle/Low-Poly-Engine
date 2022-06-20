#include "Application.h"

#include <iostream>
#include "Shader.h"

#include "OpenglError.h"

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

	float positions[8] = {
		-0.5f, -0.5f,
		 0.5f, -0.5f,
		 0.5f,  0.5f,
		-0.5f,  0.5f
	};

	unsigned int indexes[] = {
		0, 1, 2,
		2, 3, 0
	};


	/* Vertex Array */
	unsigned int vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	/* Vertex Buffer */
	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), positions, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

	/* Index Buffer */
	unsigned int ibo;
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(int), indexes, GL_STATIC_DRAW);

	/* Bind Buffers and Vertex Array */
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	while (!glfwWindowShouldClose(this->window)) {

		glBindVertexArray(vao);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

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
	glClearColor(background_color);

	Shader shader("res/shaders/Basic.shader");

	shader.UseProgram();

	for (int i = 0; i < displays.size();i++) {
		displays[i].SetDisplay();

		if(i == 0)
			shader.SetVec4("u_Color", BLACK.vec4());
		else if(i == 1)
			shader.SetVec4("u_Color", GREEN.vec4());
		else if(i == 2)
			shader.SetVec4("u_Color", BLUE.vec4());
		else if(i == 3)
			shader.SetVec4("u_Color", RED.vec4());

		/* ---- Draw here ---- */

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

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

	/* Set GLFW Version */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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
