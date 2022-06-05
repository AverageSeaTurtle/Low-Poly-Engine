#include "Display.h"

Display::Display(int x, int y, int width, int height) 
	: Viewport::Viewport(x, y, width, height), current_camera(nullptr)
{


}

Display::~Display()
{
	current_camera = nullptr;
	delete[] current_camera;
}

Display::Display(Display& other) : 
	Viewport(other), current_camera(nullptr)
{
	current_camera = &other.GetCurrentCamera();
}

void Display::SetDisplay()
{
	SetViewport();
	current_camera->SetCamera();
	
}

void Display::SetCurrentCamera(Camera& camera) 
{
	current_camera = &camera;
}

Camera& Display::GetCurrentCamera()
{
	return *current_camera;
}
