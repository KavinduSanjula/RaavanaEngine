#include "window.h"

namespace RE {

	Window::Window(int width, int height, const std::string& title)
		:m_Width(width), m_Height(height), m_Title(title)
	{
		if (!glfwInit()) {
			m_Error = true;
			return;
		}

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), NULL, NULL);
		if (!m_Window) {
			m_Error = true;
			glfwTerminate();
			return;
		}

		glfwMakeContextCurrent(m_Window);
		glewInit();
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	bool Window::ShouldClose() const
	{
		return glfwWindowShouldClose(m_Window);
	}

	void Window::SwapBuffers() const
	{
		glfwSwapBuffers(m_Window);
	}

	void Window::PollEvents() const
	{
		glfwPollEvents();
	}

}