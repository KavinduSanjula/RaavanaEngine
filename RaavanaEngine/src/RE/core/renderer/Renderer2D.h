#pragma once
#include "repch.h"

#include "renderer/VertexArray.h"
#include "renderer/VertexBuffer.h"
#include "renderer/IndexBuffer.h"
#include "renderer/Shader.h"
#include "renderer/Texture.h"
#include "renderer/BasicRenderer.h"
#include "shapes/Quad.h"

#define MAX_QUAD_COUNT 100
#define MAX_TEXTURE_COUNT 10


namespace RE {

	class Renderer2D {
	private:

		int m_SubmitCount = 0;
		int m_PtrOffset = 0;
		int m_DrawCallCount = 0;
		int m_IndexToDraw = 0;
		float m_TextureID = 1;

		Vertex m_Vertices[4 * MAX_QUAD_COUNT];
		uint32_t m_Indeces[6 * MAX_QUAD_COUNT];
		std::vector<Quad> m_Quads;

		Ref<VertexArray> m_VA;
		Ref<VertexBuffer> m_VB;
		Ref<IndexBuffer> m_IB;
		Ref<Shader> m_Shader;

		std::unordered_map<std::string, float> m_TextureMap;
		std::array<Ref<Texture>, MAX_TEXTURE_COUNT> m_Textures;

		BasicRenderer m_Renderer;

	public:
		Renderer2D();

		void BeginBatch();
		void Submit(const Quad& quad);
		void Flush();
		void Clear();

		inline int GetDrawCallCount() const { return m_DrawCallCount; }

	private:
		void Draw();
		void GenerateIndeces();
		void CreateTexture(const Quad& path);

	};

}
