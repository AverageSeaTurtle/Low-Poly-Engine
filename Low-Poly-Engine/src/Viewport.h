#pragma once

#include <GLFW/glfw3.h>
#include "Node.h"

class Viewport
{
public:
	Viewport(int x, int y, int width, int height);
	Viewport(const Viewport& other);
	~Viewport();

protected:
	void SetViewport();

	int x, y;
	int width, height;
};