#pragma once
#include "repch.h"
#include "core.h"
#include "opengl.h"

namespace RE {

	class VertexBuffer {
	private:
		uint32_t m_RendererID;

	public:
		static Ref<VertexBuffer> Create(const void* data, uint32_t size, uint32_t mode);

		VertexBuffer(const void* data, uint32_t size, uint32_t mode);
		~VertexBuffer();

		void SetData(const void* data, uint32_t size);

		void Bind() const;
		void Unbind() const;

		inline uint32_t GetRendererID() const { return m_RendererID; }
	};

}