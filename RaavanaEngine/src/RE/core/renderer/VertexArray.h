#pragma once
#include "repch.h"
#include "core.h"

#include "opengl.h"
#include "VertexBuffer.h"
#include "utils/VertexBufferLayout.h"

namespace RE {

	class VertexArray
	{
	private:
		uint32_t m_RendererID;

	public:
		static Ref<VertexArray> Create();
		VertexArray();
		~VertexArray();

		inline uint32_t GetRendererID() const { return m_RendererID; }

		void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
		void Bind() const;
		void UnBind() const;
	};
}