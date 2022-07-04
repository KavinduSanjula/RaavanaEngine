#include "repch.h"
#include "Input.h"

namespace RE {

	Input::Input(GLFWwindow* window)
	{
		m_Window = window;
	}

	bool Input::KeyDown(int key) {
		auto status = glfwGetKey(instance->m_Window, key);
		return status == GLFW_PRESS || status == GLFW_REPEAT;
	}

	bool Input::MouseButtonDown(int button)
	{
		auto status = glfwGetMouseButton(instance->m_Window, button);
		return status == GLFW_PRESS;
	}

	glm::vec2 Input::CursorPositon()
	{
		double x, y;
		glfwGetCursorPos(instance->m_Window, &x, &y);
		glm::vec2 pos({ x,y });
		return pos;
	}

}