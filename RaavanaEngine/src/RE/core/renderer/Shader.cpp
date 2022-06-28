#include "repch.h"
#include "Shader.h"

namespace RE {

	Ref<Shader> Shader::Create(const std::string& shaderPath) {
		return std::make_shared<Shader>(shaderPath);
	}

	Shader::Shader(const std::string& shaderPath)
		:m_ShaderPath(shaderPath)
	{
		ReadShader();
		uint32_t vertexShader = compile_shader(GL_VERTEX_SHADER, m_Source.VertexShaderSource);
		uint32_t fragmentShader = compile_shader(GL_FRAGMENT_SHADER, m_Source.FragmentShaderSource);

		m_RendererID = glCreateProgram();
		glAttachShader(m_RendererID, vertexShader);
		glAttachShader(m_RendererID, fragmentShader);
		glLinkProgram(m_RendererID);

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		glUseProgram(m_RendererID);
	}

	Shader::~Shader()
	{
		glDeleteProgram(m_RendererID);
	}

	void Shader::Bind() const
	{
		glUseProgram(m_RendererID);
	}

	void Shader::Unbind() const
	{
		glUseProgram(0);
	}

	void Shader::ReadShader()
	{
		std::ifstream file(m_ShaderPath);
		std::string line;

		if (!file.is_open()) {
			LOG_ERR("File not found " + m_ShaderPath);
			ASSERT(false);
		}

		int i = 0;
		while (getline(file, line)) {

			if (line.find("#type Fragment") != line.npos) {
				i = 1;
				continue;
			}
			else if (line.find("#type Vertex") != line.npos) {
				i = 0;
				continue;
			}

			m_Source[i] += line + "\n";
		}
	}

	uint32_t Shader::compile_shader(uint32_t type, std::string shaderSource) const
	{
		const char* shader_source = shaderSource.c_str();
		uint32_t shader = glCreateShader(type);
		glShaderSource(shader, 1, &shader_source, NULL);
		glCompileShader(shader);

		int  success;
		char infoLog[512];
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

		if (!success) {
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			std::cout << infoLog << std::endl;
			ASSERT(false);
		}

		return shader;
	}

}