#include "repch.h"

#include "window/window.h"

#include "renderer/VertexBuffer.h"
#include "renderer/VertexArray.h"
#include "renderer/IndexBuffer.h"
#include "renderer/Shader.h"


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




	while (!window->ShouldClose()) {

		glClear(GL_COLOR_BUFFER_BIT);



		window->Update();
	}

}
