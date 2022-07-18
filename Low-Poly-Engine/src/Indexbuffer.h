#pragma once

#include <gl/glew.h>

class IndexBuffer
{
public:
	IndexBuffer();
	IndexBuffer(const GLint* data, unsigned int count);
	~IndexBuffer();

	void Bind() const;
	void Unbind() const;

	void SetData(const GLint* data, unsigned int count);

	inline unsigned int GetCount() const { return m_Count; };

private:
	unsigned int m_RendererId;
	unsigned int m_Count;
};
