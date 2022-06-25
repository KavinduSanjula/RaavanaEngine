#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <string>

namespace RE {
	class Window {
	private:
		bool m_Error;
		int m_Width, m_Height;
		std::string m_Title;

		GLFWwindow* m_Window;

	public:
		Window(int width, int height, const std::string& title);
		~Window();

		inline bool HasErrors() const { return m_Error; }
		bool ShouldClose() const;
		
		void SwapBuffers() const;
		void PollEvents() const;

	};
}