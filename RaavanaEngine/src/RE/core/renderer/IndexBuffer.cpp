#include "repch.h"
#include "IndexBuffer.h"

namespace RE {

	Ref<IndexBuffer> IndexBuffer::Create(const void* data, uint32_t size, uint32_t mode)
	{
		return std::make_shared<IndexBuffer>(data, size, mode);
	}

	IndexBuffer::IndexBuffer(const void* data, uint32_t count, uint32_t mode)
		:m_IndexCount(count)
	{
		glGenBuffers(1, &m_RendererID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), data, mode);
	}

	IndexBuffer::~IndexBuffer()
	{
		glDeleteBuffers(1, &m_RendererID);
	}

	void IndexBuffer::SetData(const void* data, uint32_t size)
	{
		glBufferSubData(GL_ELEMENT_ARRAY_BUFFER,0, size, data);
	}

	void IndexBuffer::Bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
	}

	void IndexBuffer::Unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

}