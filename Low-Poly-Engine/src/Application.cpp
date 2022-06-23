#include "Application.h"

#include <iostream>
#include "Shader.h"

#include "OpenglError.h"
#include "Renderer.h"
#include "Objectbuffer.h"

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

	ObjectBuffer obj("res/objects/car.obj");

	Renderer renderer;
	Shader shader("res/shaders/Basic.shader");
	shader.UseProgram();

	glm::mat4 trans = glm::mat4(1.0f);

	float rotation = 0;

	while (!glfwWindowShouldClose(this->window)) {

		rotation += 1.0f;
		if (rotation > 360)
			rotation = 0;
		
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

			trans = glm::rotate(glm::mat4(1.0f), glm::radians(rotation), glm::vec3(0.0f, 1.0f, 1.0f));
			trans = glm::scale(trans, glm::vec3(0.001f, 0.001f, 0.001f));

			shader.SetMat4("transform", trans);

			renderer.Draw(obj, shader);
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
