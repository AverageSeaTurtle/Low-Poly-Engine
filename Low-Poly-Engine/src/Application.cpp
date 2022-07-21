#include "Application.h"

#include <iostream>
#include "Shader.h"

#include "OpenglError.h"
#include "Renderer.h"
#include "Mesh.h"
#include "Texture.h"
#include "Model.h"

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

	Model model0("res/objects/plane.obj");
	Texture texture1("res/textures/plane.png");

	Renderer renderer;
	Shader shader("res/shaders/Basic.shader");
	shader.UseProgram();

	glm::mat4 trans = glm::mat4(1.0f);

	float rotation = 0;

	while (!glfwWindowShouldClose(this->window)) {

		rotation += 1.0f;
		if (rotation > 360)
			rotation = 0;
		
		renderer.Clear(background_color);

		displays[0].SetDisplay();

		trans = glm::mat4(1.0f);
		trans = glm::scale(trans, glm::vec3(0.3f, 0.3f, 0.3f));
		trans = glm::rotate(trans, glm::radians(rotation), glm::vec3(0.0f, 1.0f, 0.2f));
		shader.SetMat4("transform", trans);
		renderer.Draw(model0, texture1, shader);

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

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW);
	glCullFace(GL_BACK);
	
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

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
