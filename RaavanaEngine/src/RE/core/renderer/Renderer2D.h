#pragma once
#include "repch.h"

#include "renderer/VertexArray.h"
#include "renderer/VertexBuffer.h"
#include "renderer/IndexBuffer.h"
#include "renderer/Shader.h"
#include "renderer/BasicRenderer.h"
#include "shapes/Quad.h"


namespace RE {

	class Renderer2D {
	private:
		Vertex m_Vertices[4]{};
		uint32_t m_Indeces[6];

		Ref<VertexArray> m_VA;
		Ref<VertexBuffer> m_VB;
		Ref<IndexBuffer> m_IB;
		Ref<Shader> m_Shader;

		BasicRenderer renderer;

	public:
		Renderer2D(const Quad& quad);
		void Draw();

	private:

	};

}
