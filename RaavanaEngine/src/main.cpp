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

	RE::Quad quad({ 400,300 }, { 500,250 }, { 1.0,1.0,0.0,1.0 });
	RE::Quad quad2({ 20,20 }, { 500,250 }, { 1.0,1.0,0.0,1.0 });


	while (!window->ShouldClose()) {
		renderer.Clear();

		renderer.BeginBatch();
		renderer.Submit(quad);
		renderer.Submit(quad2);
		renderer.Flush();

		//LOG_INF(renderer.GetDrawCallCount());
		window->Update();
	}
	//system("PAUSE");
}
