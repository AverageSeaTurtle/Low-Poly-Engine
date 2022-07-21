#include "Renderer.h"
#include "OpenglError.h"

void Renderer::Draw(const VertexArray& vao, const IndexBuffer& ibo, const Shader& shader) const
{
	shader.UseProgram();
	vao.Bind();
	ibo.Bind();

	glDrawElements(GL_TRIANGLES, ibo.GetCount(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::Draw(const Mesh& mesh, const Shader& shader) const
{
	shader.UseProgram();
	mesh.Bind();

	glDrawElements(GL_TRIANGLES, mesh.GetIndexBuffer().GetCount(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::Draw(const Mesh& mesh, const Texture& texture, const Shader& shader) const
{
	shader.UseProgram();
	mesh.Bind();
	texture.Bind();
	glDrawElements(GL_TRIANGLES, mesh.GetIndexBuffer().GetCount(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::Draw (const Model& model, const Texture& texture, const Shader& shader) const
{
	shader.UseProgram();
	texture.Bind();
	for (auto& mesh : model.getMeshes()) {
		mesh.Bind();
		glDrawElements(GL_TRIANGLES, mesh.GetIndexBuffer().GetCount(), GL_UNSIGNED_INT, nullptr);
	}
}

void Renderer::Clear() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::Clear(const COLOR::RGB_f& color) const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(color.r, color.g, color.b, color.alpha);
}
