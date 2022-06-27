#include "repch.h"
#include "VertexBuffer.h"

namespace RE {

	Ref<VertexBuffer> VertexBuffer::Create(const void* data, uint32_t size, uint32_t mode)
	{
		return std::make_shared<VertexBuffer>(data, size, mode);
	}

	VertexBuffer::VertexBuffer(const void* data, uint32_t size, uint32_t mode)
	{
		glGenBuffers(1, &m_RendererID);
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ARRAY_BUFFER, size, data, mode);

	}

	VertexBuffer::~VertexBuffer()
	{
		glDeleteBuffers(1, &m_RendererID);
	}

	void VertexBuffer::SetData(const void* data, uint32_t size)
	{
		glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
	}

	void VertexBuffer::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	}

	void VertexBuffer::Unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

}