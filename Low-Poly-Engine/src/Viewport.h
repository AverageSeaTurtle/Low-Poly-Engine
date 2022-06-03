#pragma once

#include <GLFW/glfw3.h>

class Viewport
{
public:

	Viewport(int x, int y, int width, int height);
	~Viewport();

	void SetViewport();

private:
	int x, y;
	int width, height;
};