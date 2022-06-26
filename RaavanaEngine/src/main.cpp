#include "repch.h"

#include "window/window.h"

int main() {
	
	RE::Ref<RE::Window> window = RE::Window::Create(1280, 720, "Raavana Engine");

	if (window->HasErrors())
		return -1;

	window->DumpGlInfo();

	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

	while (!window->ShouldClose()) {

		glClear(GL_COLOR_BUFFER_BIT);


		glBegin(GL_TRIANGLES);

		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);

		glEnd();

		window->Update();
	}

}