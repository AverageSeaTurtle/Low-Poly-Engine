#pragma once

#include <gl/glew.h>
#include <GLFW/glfw3.h>

#include "Vertexarray.h"
#include "Indexbuffer.h"
#include "Shader.h"
#include "Color.h"

class Renderer
{
public:
	Renderer() {};

	void Draw(const VertexArray& vao, const IndexBuffer& ibo, const Shader& shader) const;
	void Clear() const;
	void Clear(const COLOR::RGB_f& color) const;

private:

};