#include "repch.h"
#include "Renderer2D.h"

namespace RE {


	Renderer2D::Renderer2D(const Quad& quad)
	{
		m_Indeces[0] = 0;
		m_Indeces[1] = 1;
		m_Indeces[2] = 2;
		m_Indeces[3] = 2;
		m_Indeces[4] = 3;
		m_Indeces[5] = 0;

		memcpy(m_Vertices, quad.GetVertices().data(), 4 * sizeof(Vertex));

		m_VA = VertexArray::Create();
		m_VB = VertexBuffer::Create(m_Vertices, sizeof(m_Vertices), GL_STATIC_DRAW);
		m_IB = IndexBuffer::Create(m_Indeces, 6, GL_STATIC_DRAW);
		m_Shader = Shader::Create("res/basic.shader");

		m_VA->AddBuffer(*m_VB, Vertex::GetLayout());
	}

	void Renderer2D::Draw()
	{
		renderer.Clear();
		renderer.Draw(m_VA, m_IB, m_Shader);

	}

}