#pragma once

#include "repch.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>


#define MAX_KEY_COUNT 1024

#define RE_KEY_A 65
#define RE_KEY_B 66
#define RE_KEY_C 66
#define RE_KEY_D 67
#define RE_KEY_E 68
#define RE_KEY_F 69
#define RE_KEY_ENTER  GLFW_KEY_ENTER

namespace RE {

	class Window {

	private:
		bool m_Error;
		int m_Width, m_Height;
		std::string m_Title;

		GLFWwindow* m_Window;

		bool m_Keys[MAX_KEY_COUNT]{};

	public:
		Window(int width, int height, const std::string& title);
		~Window();

		inline bool HasErrors() const { return m_Error; }
		bool ShouldClose() const;

		void Update();

		bool IsKeyPressed(int key) const;


		void DumpGlInfo() const;
		

	private:
		void SetSize(int width, int height);

	private:
		friend static void window_size_callback(GLFWwindow* window, int width, int height);
		friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	};

	
}