#pragma once
#include "repch.h"
#include "core.h"
#include "opengl.h"

namespace RE {

	struct ShaderSource {
		std::string VertexShaderSource;
		std::string FragmentShaderSource;

		std::string& operator[] (int index) {
			if (index == 0)
				return VertexShaderSource;
			else
				return FragmentShaderSource;
		}
	};

	class Shader {
	private:
		uint32_t m_RendererID;
		std::string m_ShaderPath;
		ShaderSource m_Source;

	public:
		Shader(const std::string& shaderPath);
		~Shader();

		void Bind() const;
		void Unbind() const;

		inline uint32_t GetRendererID() const { return m_RendererID; }

	private:
		void ReadShader();

		uint32_t compile_shader(uint32_t type, std::string shaderSource) const;
	};
}
