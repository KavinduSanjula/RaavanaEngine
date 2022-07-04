#pragma once
#include "repch.h"
#include <GLFW/glfw3.h>
#include "glm/glm.hpp"

namespace RE {

	class CursorPos {
		float x, y;
	};
	
	class Input {

	private:
		GLFWwindow* m_Window;

	public:
		Input(GLFWwindow* window);


	public:
		static Input* instance;
		static bool KeyDown(int key);
		static bool MouseButtonDown(int button);
		static glm::vec2 CursorPositon();
	};

}