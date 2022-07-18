#include "Application.h"

#include <iostream>
#include "Shader.h"

#include "OpenglError.h"
#include "Renderer.h"
#include "Objectbuffer.h"
#include "Mesh.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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
		Display(0, 0, GetWindowWidth(), GetWindowHeight()) );

	Mesh mesh("res/objects/car.obj");

	Renderer renderer;
	Shader shader("res/shaders/Basic.shader");
	shader.UseProgram();

	glm::mat4 trans = glm::mat4(1.0f);

	float rotation = 0;

	float x = 0;


	while (!glfwWindowShouldClose(this->window)) {

		rotation += 1.0f;
		if (rotation > 360)
			rotation = 0;

		x += 10;
		if (x > 1200)
			x = -1200;
		
		/* Render here */
		renderer.Clear(background_color);

		displays[0].SetDisplay();
		shader.SetVec4("u_Color", RED.vec4());

		trans = glm::mat4(1.0f);
		trans = glm::scale(trans, glm::vec3(0.001f, 0.001f, 0.001f));
		trans = glm::translate(trans, glm::vec3(x, 0.0f, 0.0f));
		trans = glm::rotate(trans, glm::radians(rotation), glm::vec3(0.0f, 1.0f, 1.0f));

		shader.SetMat4("transform", trans);

		renderer.Draw(mesh, shader);

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
