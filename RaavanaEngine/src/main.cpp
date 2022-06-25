#include "window/window.h"

int main() {
	RE::Window window(1280, 720, "Raavana Engine");

	if (window.HasErrors())
		return -1;

	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

	while (!window.ShouldClose()) {
		glClear(GL_COLOR_BUFFER_BIT);
		window.SwapBuffers();
		window.PollEvents();

	}
}