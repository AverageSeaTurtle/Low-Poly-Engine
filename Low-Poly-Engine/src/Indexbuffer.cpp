#include "IndexBuffer.h"

#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "OpenglError.h"

IndexBuffer::IndexBuffer()
	: m_Count(0)
{
	glGenBuffers(1, &m_RendererId);
}

IndexBuffer::IndexBuffer(const GLint* data, unsigned int count)
	: m_Count(count)
{
	glGenBuffers(1, &m_RendererId);
	SetData(data, count);
}

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &m_RendererId);
}

void IndexBuffer::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererId);
}

void IndexBuffer::Unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IndexBuffer::SetData(const GLint* data, unsigned int count)
{
	m_Count = count;
	Bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
}

