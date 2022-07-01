#include "repch.h"

#include "window/window.h"
#include "renderer/Renderer2D.h"
#include "shapes/Quad.h"

int main() {
	
	RE::Ref<RE::Window> window = RE::Window::Create(1280, 720, "Raavana Engine");

	if (window->HasErrors())
		return -1;

	window->DumpGlInfo();

	RE::Renderer2D renderer;

	RE::Quad quad({ 540,310 }, { 200,100 }, { 1.0,1.0,0.0,1.0 });


	while (!window->ShouldClose()) {
		renderer.Clear();

		renderer.BeginBatch();
		renderer.Submit(quad);
		renderer.Flush();

		LOG_INF(renderer.GetDrawCallCount());
		window->Update();
	}

}
