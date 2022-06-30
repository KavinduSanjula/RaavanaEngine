#include "repch.h"
#include "Renderer2D.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace RE {


	Renderer2D::Renderer2D()
	{

		GenerateIndeces();

		m_VA = VertexArray::Create();
		m_VB = VertexBuffer::Create(nullptr, MAX_QUAD_COUNT * 4 * sizeof(Vertex), GL_DYNAMIC_DRAW);
		m_IB = IndexBuffer::Create(nullptr, MAX_QUAD_COUNT * 6, GL_DYNAMIC_DRAW);
		m_Shader = Shader::Create("res/basic.shader");

		glm::mat4 proj = glm::ortho(0.0f, 1280.0f, 0.0f, 720.0f, -1.0f, 1.0f);

		m_Shader->Bind();
		m_Shader->SetUniformMat4("uProj", proj);
		m_Shader->Unbind();

		m_IB->SetData(m_Indeces, sizeof(m_Indeces));
		m_VA->AddBuffer(*m_VB, Vertex::GetLayout());
	}

	void Renderer2D::BeginBatch()
	{
		m_SubmitCount = 0;
		m_PtrOffset = 0;
		m_Quads.clear();
	}

	void Renderer2D::Submit(const Quad& quad)
	{
		if (m_SubmitCount >= MAX_QUAD_COUNT) {
			Flush();
			BeginBatch();
		}

		m_Quads.push_back(quad);
		m_IndexToDraw += 6;
		m_SubmitCount++;

	}

	void Renderer2D::Flush()
	{
		m_IB->SetData(m_Indeces, sizeof(m_Indeces));

		memset(m_Vertices, 0, MAX_QUAD_COUNT * 4 * sizeof(Vertex));

		int offset = 0;
		for (auto quad : m_Quads) {
			auto vertices = quad.GetVertices();
			memcpy(m_Vertices + offset, vertices.data(), 4 * sizeof(Vertex));
			offset += 4;
		}

		m_VB->SetData(m_Vertices, sizeof(m_Vertices));

		Draw();
	}

	void Renderer2D::Clear()
	{
		m_Renderer.Clear();
		m_DrawCallCount = 0;
	}

	void Renderer2D::Draw()
	{
		m_Renderer.Draw(*m_VA, *m_IB, *m_Shader, m_IndexToDraw);
		m_DrawCallCount++;
	}

	void Renderer2D::GenerateIndeces()
	{
		int ptr = 0;
		for (int i = 0; i < MAX_QUAD_COUNT; i++) {
			m_Indeces[ptr++] = 0 + (i * 4);
			m_Indeces[ptr++] = 1 + (i * 4);
			m_Indeces[ptr++] = 2 + (i * 4);
			m_Indeces[ptr++] = 2 + (i * 4);
			m_Indeces[ptr++] = 3 + (i * 4);
			m_Indeces[ptr++] = 0 + (i * 4);
		}
	}

}