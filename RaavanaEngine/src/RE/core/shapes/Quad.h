#pragma once
#include "repch.h"
#include "Vertex.h"

namespace RE {

	class Quad {
	private:
		Vertex m_Verticis[4]{};

		vec2 m_Pos;
		vec2 m_Size;
		vec4 m_Color;

	public:
		Quad(const RE::vec2& pos, const RE::vec2& size, const RE::vec4& color);
		~Quad();
	};

}
