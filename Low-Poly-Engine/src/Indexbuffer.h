#pragma once

class IndexBuffer
{
public:
	IndexBuffer();
	IndexBuffer(const unsigned int* data, unsigned int count);
	~IndexBuffer();

	void Bind() const;
	void Unbind() const;

	void SetData(const unsigned int* data, unsigned int count);

	inline unsigned int GetCount() const { return m_Count; };

private:
	unsigned int m_RendererId;
	unsigned int m_Count;
};