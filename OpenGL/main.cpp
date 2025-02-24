#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "OpenGL32.lib")

#include "GLAD/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>
#include <string_view>
#include <functional>
#include <fstream>

namespace {
	struct rgba {
		GLfloat R;
		GLfloat G;
		GLfloat B;
		GLfloat A;
	};

	void log_writer(std::ofstream& log_lw, std::string_view& log_file_name_lw, std::string_view message) {
		log_lw.open(log_file_name_lw.data(), std::ios::out | std::ios::binary | std::ios::app);
		log_lw << message;
		log_lw.close();
	}
}

int main(int arg_counter, char* arg_value[]) {
	std::string_view log_file_name("logs");
	std::ofstream log;
	const int width = 2048;
	const int height = 1080;
	const int opengl_version_major = 4;
	const int opengl_version_minor = 6;
	rgba background = { 0.2f, 0.3f, 0.1f, 1.0f };
	std::string_view window_title = "g00dboyo";
	std::function<void(GLFWwindow*)> process_events = [](GLFWwindow* window_pe) {
		int key_state = glfwGetKey(window_pe, GLFW_KEY_ESCAPE);

		if (key_state == GLFW_PRESS) {
			glfwSetWindowShouldClose(window_pe, GLFW_TRUE);
		}

		glfwPollEvents();
		};

	int is_glfw_init = glfwInit();

	if (!is_glfw_init) {
		log_writer(log, log_file_name, "Failed to initialize GLFW \n");

		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, opengl_version_major);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, opengl_version_minor);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(width, height, window_title.data(), nullptr, nullptr);

	if (!window) {
		log_writer(log, log_file_name, "Failed to create GLFW window \n");

		glfwTerminate();

		return -1;
	}

	glfwMakeContextCurrent(window);

	GLADloadproc load_proc = reinterpret_cast<GLADloadproc>(glfwGetProcAddress);
	int is_glad_init = gladLoadGLLoader(load_proc);

	if (!is_glad_init) {
		log_writer(log, log_file_name, "Failed to initialize GLAD \n");

		glfwTerminate();

		return -1;
	}

	// GL_COLOR_BUFFER_BIT - color buffer
	// GL_DEPTH_BUFFER_BIT - depth buffer
	// GL_STENCIL_BUFFER_BIT - stencil buffer

	while (!glfwWindowShouldClose(window)) {
		glClearColor(background.R, background.G, background.B, background.A);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);

		process_events(window);
	}

	glfwTerminate();

	return 0;
}