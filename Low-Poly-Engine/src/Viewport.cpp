#include "Viewport.h"

Viewport::Viewport(int x = 0, int y = 0, int width = 100, int height = 100) 
	: x(x), y(y), width(width), height(height)
{
}

Viewport::~Viewport()
{
}

void Viewport::SetViewport()
{
	glViewport(x, y, width, height);
}
