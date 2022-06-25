#include "repch.h"
#include "window.h"


namespace RE {

	static void window_size_callback(GLFWwindow* window, int width, int height);
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

	Window::Window(int width, int height, const std::string& title)
		:m_Width(width), m_Height(height), m_Title(title), m_Error(false), m_Window(nullptr), m_CursorPosition({0,0})
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

		glfwSetWindowUserPointer(m_Window, this); //set user pointer for this instance

		glfwSetWindowSizeCallback(m_Window, window_size_callback);
		glfwSetKeyCallback(m_Window, key_callback);
		glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
		glfwSetCursorPosCallback(m_Window, cursor_position_callback);

		ClearInputs();
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	bool Window::ShouldClose() const
	{
		return glfwWindowShouldClose(m_Window);
	}

	void Window::Update()
	{
		ClearInputs();

		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

	bool Window::IsKeyPressed(int key) const
	{
		if (key < MAX_KEY_COUNT)
			return m_Keys[key];

		return false;
	}

	bool Window::IsMouseButtonPressed(int button) const
	{
		if (button < MAX_MOUSE_BUTTONS)
			return m_MouseButtons[button];

		return false;
	}

	void Window::DumpGlInfo() const
	{
		std::string version = std::string((const char*)glGetString(GL_VERSION));
		LOG_INF("OpenGL Version - " + version);
	}



	void Window::ClearInputs()
	{
		memset(m_Keys, 0, MAX_KEY_COUNT);
		memset(m_MouseButtons, 0, MAX_MOUSE_BUTTONS);
	}



	///////////////////////// callbacks /////////////////////////////////

	static void window_size_callback(GLFWwindow* window, int width, int height) {

		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->m_Width = width;
		win->m_Height = height;
		glfwSetWindowSize(window, width, height);
		glViewport(0, 0, width, height);
	}

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		if(action == GLFW_PRESS)
			win->m_Keys[key] = true;
	}

	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
	{
		LOG_INF(button);
		if (button < MAX_MOUSE_BUTTONS) {
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			if(action == GLFW_PRESS)
				win->m_MouseButtons[button] = true;
		}
	}

	static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->m_CursorPosition.x = xpos;
		win->m_CursorPosition.y = ypos;
	}

}