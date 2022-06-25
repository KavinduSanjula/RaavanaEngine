#include "repch.h"
#include "window/window.h"

int main() {
	RE::Window window(1280, 720, "Raavana Engine");

	if (window.HasErrors())
		return -1;

	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

	while (!window.ShouldClose()) {
		glClear(GL_COLOR_BUFFER_BIT);
		if (window.IsKeyPressed(RE_KEY_ENTER)) {
			std::cout << "A key pressed" << std::endl;
		}
		window.Update();


	}
}