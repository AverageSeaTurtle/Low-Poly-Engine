#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Display.h"
#include <vector>
#include <string>

class Application
{
public:
	Application(int window_width, int window_height, std::string title);
	~Application();

	void Loop();
	bool Init();

	void SetBackgroundColor(const COLOR::RGB_f& color);
	const COLOR::RGB_f GetBackgroundColor() const;

	int GetWindowWidth() const { return window_width; }
	int GetWindowHeight() const { return window_height; }

	void SetWindowWidth(int width) { window_width = width; }
	void SetWindowHeight(int height) { window_height = height; }

private:
	void Update();
	void Render();

	GLFWwindow* window;
	int window_width, window_height;

	std::string title;

	std::vector<Display> displays;
	COLOR::RGB_f background_color;

};