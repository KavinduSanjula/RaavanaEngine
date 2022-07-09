#include "repch.h"

#include "window/window.h"
#include "renderer/Renderer2D.h"
#include "renderer/Camera.h"
#include "shapes/Quad.h"


int main() {
	
	RE::Ref<RE::Window> window = RE::Window::Create(1280, 720, "Raavana Engine");

	if (window->HasErrors())
		return -1;

	window->DumpGlInfo();

	RE::Ref<RE::Camera> cam = std::make_shared<RE::Camera>(0.0f, 1280.0f, 0.0f, 720.0f);
	RE::Renderer2D* renderer = new RE::Renderer2D(cam);


	RE::Quad quad({ 400,300 }, { 500,250 }, "res/cover.jpg");
	RE::Quad quad2({ 20,20 }, { 250,250 }, "res/sanju.jpg");
	RE::Quad quad3({ 300,20 }, { 250,250 }, NO_TEXTURE, { 1.0,1.0,0.0,1.0 });


	while (!window->ShouldClose()) {

		renderer->Clear();
				
		renderer->BeginBatch();
		renderer->Submit(quad);
		renderer->Submit(quad2);
		renderer->Submit(quad3);
		renderer->Flush();

		window->Update();
	}

	delete(renderer);
}
