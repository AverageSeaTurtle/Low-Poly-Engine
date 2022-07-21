#pragma once

#include "Vertexbuffer.h"
#include "VertexbufferLayout.h"

class VertexArray
{
public:
	VertexArray();
	VertexArray(const VertexArray& other) : m_RendererId(other.getRendererId()) {}
	~VertexArray();

	void AddBuffer(const VertexBuffer& vbo, const VertexBufferLayout& layout);

	void Bind() const;
	void Unbind() const;

	unsigned int getRendererId() const { return m_RendererId; }

private:
	unsigned int m_RendererId;
};