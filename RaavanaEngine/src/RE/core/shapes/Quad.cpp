#include "repch.h"
#include "Quad.h"


namespace RE {

	void make_quad(Vertex* arr, vec2 pos, vec2 size, vec4 color);


	Quad::Quad(const RE::vec2& pos, const RE::vec2& size, const RE::vec4& color)
		:m_Pos(pos), m_Size(size), m_Color(color)
	{
		make_quad(m_Verticis, m_Pos,m_Size,m_Color);
	}

	Quad::~Quad()
	{

	}

	void make_quad(Vertex* arr, vec2 pos, vec2 size, vec4 color) {
		arr->Position = { pos.x, pos.y, 0 };
		arr->Color = color;
		arr++;

		arr->Position = { pos.x + size.x, pos.y, 0 };
		arr->Color = color;
		arr++;

		arr->Position = { pos.x + size.x, pos.y + size.y, 0 };
		arr->Color = color;
		arr++;

		arr->Position = { pos.x, pos.y + size.y, 0 };
		arr->Color = color;
	}

}