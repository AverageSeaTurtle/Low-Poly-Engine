#pragma once

#include "Viewport.h"
#include "Camera.h"
#include "Color.h"

class Display : private Viewport
{
public:
	Display(int x = 0, int y = 0, int width = 0, int height = 0);
	~Display();
	Display(Display& other);

	void SetDisplay();

	void SetCurrentCamera(Camera& camera);
	Camera& GetCurrentCamera();

private:
	Camera* current_camera;

};
