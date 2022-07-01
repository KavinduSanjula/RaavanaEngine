#pragma once
#include "repch.h"
#include "Vertex.h"


namespace RE {

	class Quad {
	private:
		mutable std::array<Vertex, 4> m_Vertices;
		std::string m_TexturePath;

		vec2 m_Pos;
		vec2 m_Size;
		vec4 m_Color;

	public:
		Quad(const RE::vec2& pos, const RE::vec2& size, const RE::vec4& color, const std::string& texture=NO_TEXTURE);
		~Quad();

		inline std::array<Vertex, 4> GetVertices() const { return m_Vertices; }
		inline std::string GetTexturePath() const { return m_TexturePath; }

		void SetTextureID(float texID) const;
	};

}
