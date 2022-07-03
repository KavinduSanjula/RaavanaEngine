#include "repch.h"
#include "Shader.h"

namespace RE {

	void create_error_shader(ShaderSource& source);


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

	void Shader::SetUniformMat4(const std::string& name, glm::mat4& mat)
	{
		glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &mat[0][0]);
	}

	void Shader::SetUniformI1(const std::string& name, int val)
	{
		glUniform1i(GetUniformLocation(name), val);
	}

	void Shader::SetUniformArrayI(const std::string& name, uint32_t count, int* data)
	{
		glUniform1iv(GetUniformLocation(name), count, data);
	}

	void Shader::ReadShader()
	{
		std::ifstream file(m_ShaderPath);
		std::string line;

		if (!file.is_open()) {
			LOG_ERR("File not found " + m_ShaderPath);
			create_error_shader(m_Source);
			return;
		}

		int i = -1;
		while (getline(file, line)) {

			if (line.find("#type Fragment") != line.npos) {
				i = 1;
				continue;
			}
			else if (line.find("#type Vertex") != line.npos) {
				i = 0;
				continue;
			}
			if (i != -1) {
				m_Source[i] += line + "\n";
			}
		}

		if (i == -1)
		{
			create_error_shader(m_Source);
			return;
		}
	}

	int Shader::GetUniformLocation(const std::string& name)
	{
		int location = glGetUniformLocation(m_RendererID, name.c_str());
		return location;
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

	void create_error_shader(ShaderSource& source) {
		std::string vs = "\n"
			"#version 330 core \n"
			"layout (location = 0) in vec3 aPos; \n"
			"void main() { \n"
			"gl_Position = vec4(aPos,1.0); \n"
			"} \n";

		std::string fs = "\n"
			"#version 330 core \n"
			"out vec4 Color; \n"
			"void main() \n"
			" { \n"
			"Color = vec4(1.0,0.0,1.0,1.0); \n"
			"} \n";

		source.VertexShaderSource = vs;
		source.FragmentShaderSource = fs;
	}

}