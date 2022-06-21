#pragma once

#include "Vertexbuffer.h"
#include "VertexbufferLayout.h"

class VertexArray
{
public:
	VertexArray();
	~VertexArray();

	void AddBuffer(const VertexBuffer& vbo, const VertexBufferLayout& layout);

	void Bind() const;
	void Unbind() const;


private:
	unsigned int m_RendererId;
};