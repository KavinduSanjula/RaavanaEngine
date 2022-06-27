#pragma once
#include "repch.h"
#include "core.h"
#include "opengl.h"

namespace RE {

	class IndexBuffer {
	private:
		uint32_t m_RendererID;

	public:
		static Ref<IndexBuffer> Create(const void* data, uint32_t size, uint32_t mode);

		IndexBuffer(const void* data, uint32_t size, uint32_t mode);
		~IndexBuffer();

		void SetData(const void* data, uint32_t size);

		void Bind() const;
		void Unbind() const;

		inline uint32_t GetRendererID() const { return m_RendererID; }
	};

}
