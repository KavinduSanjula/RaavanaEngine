#pragma once
#include "repch.h"
#include "core.h"
#include "opengl.h"

#include "glm/glm.hpp"

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
		static Ref<Shader> Create(const std::string& shaderPath);
		Shader(const std::string& shaderPath);
		~Shader();

		void Bind() const;
		void Unbind() const;

		inline uint32_t GetRendererID() const { return m_RendererID; }

		void SetUniformMat4(const std::string& name, glm::mat4& mat);
		void SetUniformI1(const std::string& name, int val);
		void SetUniformArrayI(const std::string& name, uint32_t count, int* data);

	private:
		void ReadShader();
		int GetUniformLocation(const std::string& name);

		uint32_t compile_shader(uint32_t type, std::string shaderSource) const;
	};
}
