#pragma once
#include "repch.h"
#include "Vertex.h"

namespace RE {

	class Quad {
	private:
		std::array<Vertex, 4> m_Vertices;

		vec2 m_Pos;
		vec2 m_Size;
		vec4 m_Color;

	public:
		Quad(const RE::vec2& pos, const RE::vec2& size, const RE::vec4& color);
		~Quad();

		inline std::array<Vertex, 4> GetVertices() const { return m_Vertices; }
	};

}
