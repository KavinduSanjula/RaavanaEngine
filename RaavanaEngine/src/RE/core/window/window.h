#pragma once

#include "repch.h"
#include "core.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>


#define MAX_KEY_COUNT 1024
#define MAX_MOUSE_BUTTONS 5

#define RE_KEY_A 65
#define RE_KEY_B 66
#define RE_KEY_C 66
#define RE_KEY_D 67
#define RE_KEY_E 68
#define RE_KEY_F 69
#define RE_KEY_ENTER  GLFW_KEY_ENTER



namespace RE {

	struct CursorPos {
		double x, y;
	};

	class Window {

	private:
		bool m_Error;
		int m_Width, m_Height;
		std::string m_Title;

		GLFWwindow* m_Window;

		bool m_Keys[MAX_KEY_COUNT]{};
		bool m_MouseButtons[MAX_MOUSE_BUTTONS]{};

		CursorPos m_CursorPosition;
	

	public:
		Window(int width, int height, const std::string& title);
		~Window();
		static Ref<Window> Create(int width, int height, const std::string& title);

		inline bool HasErrors() const { return m_Error; }
		bool ShouldClose() const;

		void Update();

		bool IsKeyPressed(int key) const;
		bool IsMouseButtonPressed(int button) const;

		inline CursorPos GetCursorPosition() const { return m_CursorPosition; }


		void DumpGlInfo() const;

	private:
		void ClearInputs();
		

	private:
		friend static void window_size_callback(GLFWwindow* window, int width, int height);
		friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		friend static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	};

	
}