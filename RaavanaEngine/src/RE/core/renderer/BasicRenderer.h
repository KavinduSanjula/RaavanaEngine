#pragma once
#include "repch.h"

#include "core.h"
#include "opengl.h"

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

namespace RE {
	class BasicRenderer {

	public:
		BasicRenderer() = default;
		~BasicRenderer() = default;

		void Clear() const;
		void Draw(const Ref<VertexArray>& va,const Ref<IndexBuffer>& ib, const Ref<Shader>& shader) const;
		void SetClearColor(float r, float g, float b, float a);
	};
}