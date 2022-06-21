#include "Application.h"

#include <iostream>
#include "Shader.h"

#include "OpenglError.h"
#include "Renderer.h"

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
	VertexArray vao;
	/* Vertex Buffer */
	VertexBuffer vbo(positions, 8 * sizeof(float));

	VertexBufferLayout layout;
	layout.Push<float>(2);
	vao.AddBuffer(vbo, layout);

	/* Index Buffer */
	IndexBuffer ibo(indexes, 6);

	/* Unbind Buffers and Vertex Array */
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	Renderer renderer;

	Shader shader("res/shaders/Basic.shader");
	shader.UseProgram();

	while (!glfwWindowShouldClose(this->window)) {

		/* Render here */
		renderer.Clear(background_color);

		for (int i = 0; i < displays.size(); i++) {
			displays[i].SetDisplay();

			if(i == 0)
				shader.SetVec4("u_Color", RED.vec4());
			else if(i == 1)
				shader.SetVec4("u_Color", GREEN.vec4());
			else if(i == 2)
				shader.SetVec4("u_Color", YELLOW.vec4());
			else if(i == 3)
				shader.SetVec4("u_Color", BLUE.vec4());

			renderer.Draw(vao, ibo, shader);
		}

		/* Swap front and back buffers */
		glfwSwapBuffers(this->window);

		/* Poll for and process events */
		glfwPollEvents();
	}

}

void Application::Update()
{


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
