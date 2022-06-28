#include "repch.h"

#include "window/window.h"

#include "renderer/VertexBuffer.h"
#include "renderer/VertexArray.h"
#include "renderer/IndexBuffer.h"
#include "renderer/Shader.h"
#include "renderer/BasicRenderer.h"
#include "utils/VertexBufferLayout.h"


int main() {
	
	RE::Ref<RE::Window> window = RE::Window::Create(1280, 720, "Raavana Engine");

	if (window->HasErrors())
		return -1;

	window->DumpGlInfo();

	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);


	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f,
	};

	uint32_t indeces[] = { 0,1,2 };

	RE::Ref<RE::VertexBuffer> vb = RE::VertexBuffer::Create(vertices, 3 * 3 * sizeof(float), GL_STATIC_DRAW);
	RE::Ref<RE::VertexArray> va = RE::VertexArray::Create();
	RE::Ref<RE::IndexBuffer> ib = RE::IndexBuffer::Create(indeces, 3 * sizeof(uint32_t), GL_STATIC_DRAW);
	RE::Ref<RE::Shader> shader = RE::Shader::Create("res/basic.shader");

	RE::VertexBufferLayout layout;

	layout.Push<float>(3);
	va->AddBuffer(*vb, layout);
	
	va->Bind();
	ib->Bind();
	shader->Bind();

	RE::BasicRenderer renderer;

	while (!window->ShouldClose()) {

		renderer.Clear();
		renderer.Draw(va, ib, shader);

		window->Update();
	}

}
