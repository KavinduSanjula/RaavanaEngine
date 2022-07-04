#pragma once

#include "repch.h"
#include "core.h"
#include "renderer/opengl.h"

#include <GLFW/glfw3.h>


namespace RE {

	class Window {

	private:
		bool m_Error;
		int m_Width, m_Height;
		std::string m_Title;

		GLFWwindow* m_Window;
	

	public:
		static Ref<Window> Create(int width, int height, const std::string& title);

		Window(int width, int height, const std::string& title);
		~Window();

		inline bool HasErrors() const { return m_Error; }
		inline void* GetNativeWindow() const { return m_Window; }
		inline int GetWidth() const { return m_Width; }
		inline int GetHeight() const { return m_Height; }

		bool ShouldClose() const;
		void Update();
		void DumpGlInfo() const;


	private:
		friend static void window_size_callback(GLFWwindow* window, int width, int height);
	};

	
}