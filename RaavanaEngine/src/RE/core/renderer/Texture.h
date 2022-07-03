#pragma once
#include "repch.h"
#include "core.h"
#include "opengl.h"

#include <stb-image/stb_image.h>


namespace RE {

	class Texture {
	private:
		uint32_t m_RendererID;
		int m_Width, m_Height, m_NrChannels;
		unsigned char* m_LocalBuffer;

	public:
		static Ref<Texture> Create(const std::string& filename);
		Texture(const std::string& filepath);
		~Texture();

		void Bind(unsigned int slot = 0) const;
		void Unbind();

	private:
		void CreateTexture();
	};


}