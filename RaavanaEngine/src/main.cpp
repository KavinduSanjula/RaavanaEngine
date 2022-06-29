#include "repch.h"

#include "window/window.h"
#include "renderer/Renderer2D.h"
#include "shapes/Quad.h"

int main() {
	
	RE::Ref<RE::Window> window = RE::Window::Create(1280, 720, "Raavana Engine");

	if (window->HasErrors())
		return -1;

	window->DumpGlInfo();

	RE::Quad q({-0.5f,-0.5f}, { 1, 1 }, { 1,.2,0.4,1 });
	RE::Renderer2D renderer(q);


	while (!window->ShouldClose()) {

		renderer.Draw();
		window->Update();
	}

}
