#pragma once
#include "repch.h"
#include "core.h"
#include "opengl.h"

namespace RE {

	class IndexBuffer {
	private:
		uint32_t m_RendererID;
		uint32_t m_IndexCount;

	public:
		static Ref<IndexBuffer> Create(const void* data, uint32_t count, uint32_t mode);

		IndexBuffer(const void* data, uint32_t count, uint32_t mode);
		~IndexBuffer();

		void SetData(const void* data, uint32_t size);

		void Bind() const;
		void Unbind() const;

		inline uint32_t GetRendererID() const { return m_RendererID; }
		inline uint32_t GetIndexCount() const { return m_IndexCount; }
	};

}
