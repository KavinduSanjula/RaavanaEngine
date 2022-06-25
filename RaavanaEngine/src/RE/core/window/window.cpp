#include "repch.h"
#include "window.h"


namespace RE {

	static void window_size_callback(GLFWwindow* window, int width, int height);
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

	Window::Window(int width, int height, const std::string& title)
		:m_Width(width), m_Height(height), m_Title(title), m_Error(false), m_Window(nullptr)
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

		for (int i = 0; i < 1024; i++)
			m_Keys[i] = false;
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
		for (int i = 0; i < 1024; i++)
			m_Keys[i] = false;

		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

	bool Window::IsKeyPressed(int key) const
	{
		if (key < MAX_KEY_COUNT)
			return m_Keys[key];

		return false;
	}

	void Window::DumpGlInfo() const
	{
		std::string version = std::string((const char*)glGetString(GL_VERSION));
		LOG_INF("OpenGL Version - " + version);
	}

	void Window::SetSize(int width, int height)
	{
		m_Width = width;
		m_Height = height;
		glfwSetWindowSize(m_Window, m_Width, m_Height);
	}




	///////////////////////// callbacks /////////////////////////////////

	static void window_size_callback(GLFWwindow* window, int width, int height) {

		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->SetSize(width, height);
	}

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		if(action == GLFW_PRESS)
			win->m_Keys[key] = true;
	}

}