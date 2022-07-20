#pragma once

#include <gl/glew.h>
#include <GLFW/glfw3.h>

#include "Shader.h"
#include "Color.h"
#include "Mesh.h"
#include "Texture.h"

class Renderer
{
public:
	Renderer() {};

	void Draw(const VertexArray& vao, const IndexBuffer& ibo, const Shader& shader) const;
	void Draw(const Mesh& mesh, const Shader& shader) const;
	void Draw(const Mesh& mesh, const Texture& texture, const Shader& shader) const;

	void Clear() const;
	void Clear(const COLOR::RGB_f& color) const;

private:

};