#pragma once

#include "Node.h"
#include <GLFW/glfw3.h>

class Camera : public Node
{
public:
	Camera();
	~Camera();

	void SetCamera();

private:
	virtual void Update();

	Vector3D focal_point;
	Vector3D up_direction;
};