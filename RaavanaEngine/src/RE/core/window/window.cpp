#include "repch.h"
#include "window.h"
//#include "Input.h"


namespace RE {

	static void window_size_callback(GLFWwindow* window, int width, int height);

	Ref<Window> Window::Create(int width, int height, const std::string& title)
	{
		return std::make_shared<Window>(width, height, title);
	}

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

		LOG_INF("Window Created!");

		glfwMakeContextCurrent(m_Window);
		glewInit();
		glEnable(GL_DEBUG_OUTPUT);
		glDebugMessageCallback(MessageCallback,0);

		glfwSetWindowUserPointer(m_Window, this); //set user pointer for this instance

		glfwSetWindowSizeCallback(m_Window, window_size_callback);

		//Input::instance = new Input(m_Window);

	}

	Window::~Window()
	{
		glfwTerminate();
		LOG_INF("Window Destroyed!");
	}


	bool Window::ShouldClose() const
	{
		return glfwWindowShouldClose(m_Window);
	}

	void Window::Update()
	{
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}


	void Window::DumpGlInfo() const
	{
		std::string version = std::string((const char*)glGetString(GL_VERSION));
		LOG_INF("OpenGL Version - " + version);
	}


	///////////////////////// callbacks /////////////////////////////////

	static void window_size_callback(GLFWwindow* window, int width, int height) {

		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->m_Width = width;
		win->m_Height = height;
		glfwSetWindowSize(window, width, height);
		glViewport(0, 0, width, height);
	}

}