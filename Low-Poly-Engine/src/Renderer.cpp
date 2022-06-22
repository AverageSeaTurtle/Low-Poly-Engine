#include "Renderer.h"
#include "OpenglError.h"

void Renderer::Draw(const VertexArray& vao, const IndexBuffer& ibo, const Shader& shader) const
{
	shader.UseProgram();
	vao.Bind();
	ibo.Bind();

	glDrawElements(GL_TRIANGLES, ibo.GetCount(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::Draw(const ObjectBuffer& obj, const Shader& shader) const
{
	shader.UseProgram();
	obj.Bind();

	glDrawElements(GL_TRIANGLES, obj.GetIndexBuffer().GetCount(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::Clear() const
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::Clear(const COLOR::RGB_f& color) const
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(color.r, color.g, color.b, color.alpha);
}
