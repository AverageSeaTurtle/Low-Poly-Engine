#pragma once

class VertexBuffer
{
public:
	VertexBuffer(const void* data, unsigned int size);
	VertexBuffer();
	~VertexBuffer();

	void Bind() const;
	void Unbind() const;

	void SetData(const void* data, unsigned int size);

private:
	unsigned int m_RendererId;

};