#pragma once
#include "repch.h"
#include "Vertex.h"


namespace RE {

	class Quad {
	private:
		mutable std::array<Vertex, 4> m_Vertices;
		std::string m_TexturePath;

		Float2 m_Pos;
		Float2 m_Size;
		Float4 m_Color;

	public:
		Quad(const Float2& pos, const Float2& size, const std::string& texture, const Float4& color = {1.0,1.0,1.0,1.0});
		~Quad();

		inline std::array<Vertex, 4> GetVertices() const { return m_Vertices; }
		inline std::string GetTexturePath() const { return m_TexturePath; }

		void SetTextureID(float texID) const;
	};

}
