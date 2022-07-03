#include "repch.h"
#include "Texture.h"


namespace RE {


	Ref<Texture> Texture::Create(const std::string& filename)
	{
		return std::make_shared<Texture>(filename);
	}

	Texture::Texture(const std::string& filepath)
		:m_Width(0), m_Height(0), m_NrChannels(0), m_RendererID(0), m_LocalBuffer(nullptr)

	{
		if (filepath == NO_TEXTURE) {
			unsigned char data[] = { 255,255,255,255 };
			m_LocalBuffer = data;
			m_Width = 1;
			m_Height = 1;
			CreateTexture();
		}
		else {
			stbi_set_flip_vertically_on_load(1);
			m_LocalBuffer = stbi_load(filepath.c_str(), &m_Width, &m_Height, &m_NrChannels, 4);
			CreateTexture();
			stbi_image_free(m_LocalBuffer);
		}

	}

	Texture::~Texture()
	{
		glDeleteTextures(1, &m_RendererID);
	}

	void Texture::Bind(unsigned int slot) const
	{
		glActiveTexture(GL_TEXTURE0 + slot);
		glBindTexture(GL_TEXTURE_2D, m_RendererID);
	}

	void Texture::Unbind()
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void Texture::CreateTexture()
	{
		glGenTextures(1, &m_RendererID);
		glBindTexture(GL_TEXTURE_2D, m_RendererID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer);
		glGenerateMipmap(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

}