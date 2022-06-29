#include "repch.h"
#include "Quad.h"


namespace RE {

	void make_quad(std::array<Vertex, 4>& arr, vec2 pos, vec2 size, vec4 color);


	Quad::Quad(const RE::vec2& pos, const RE::vec2& size, const RE::vec4& color)
		:m_Pos(pos), m_Size(size), m_Color(color)
	{
		make_quad(m_Vertices, m_Pos,m_Size,m_Color);
	}

	Quad::~Quad()
	{

	}

	void make_quad(std::array<Vertex, 4>& arr, vec2 pos, vec2 size, vec4 color) {
		arr[0].Position = { pos.x, pos.y, 0 };
		arr[0].Color = color;

		arr[1].Position = { pos.x + size.x, pos.y, 0 };
		arr[1].Color = color;

		arr[2].Position = { pos.x + size.x, pos.y + size.y, 0 };
		arr[2].Color = color;

		arr[3].Position = { pos.x, pos.y + size.y, 0 };
		arr[3].Color = color;
	}

}