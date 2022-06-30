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


	while (!window->ShouldClose()) {
		renderer.Clear();

		renderer.BeginBatch();
		for (int x = 0; x < 1280; x += 20) {
			for (int y = 0; y < 720; y += 20) {
				RE::vec2 pos({ (float)x,(float)y });
				RE::Quad q(pos, { 19,19 }, { 1.0,1.0,0.0,1.0 });
				renderer.Submit(q);
			}
		}
		renderer.Flush();

		LOG_INF(renderer.GetDrawCallCount());
		window->Update();
	}

}
