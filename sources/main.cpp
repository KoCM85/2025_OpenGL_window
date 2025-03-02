#include <iostream>
#include <string>
#include <functional>
#include <fstream>

#include "GLAD/glad.h"
#include "GLFW/glfw3.h"

#include "version.h"

namespace {
	struct rgba {
		GLfloat R;
		GLfloat G;
		GLfloat B;
		GLfloat A;
	};

	void log_writer(std::ofstream& log_lw, std::string_view& log_file_name_lw, std::string_view message_lw);

	void append_title(std::string& window_title_at);
}

int main(int arg_counter, char* arg_value[]) {
	std::string_view log_file_name("logs");
	std::ofstream log;
	const int width = 2048;
	const int height = 1080;
	const int opengl_version_major = 4;
	const int opengl_version_minor = 5;
	rgba background = { 0.2f, 0.3f, 0.1f, 1.0f };
	std::string window_title = "g00dboyo on ";
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
	
#if defined(__APPLE__) || defined(__MACH__)
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif



	append_title(window_title);

	GLFWwindow* window = glfwCreateWindow(width, height, window_title.data(), nullptr, nullptr);

	if (!window) {
		log_writer(log, log_file_name, "Failed to create GLFW window \n");

		glfwTerminate();

		return -1;
	}

	glfwMakeContextCurrent(window);

	/* GLAD
	GLADloadproc load_proc = reinterpret_cast<GLADloadproc>(glfwGetProcAddress);
	int is_glad_init = gladLoadGLLoader(load_proc);
	*/

	// GLAD2
	GLADloadfunc load_proc = reinterpret_cast<GLADloadfunc>(glfwGetProcAddress);
	int is_glad_init = gladLoadGL(load_proc);

	if (!is_glad_init) {
		log_writer(log, log_file_name, "Failed to initialize GLAD \n");

		glfwTerminate();

		return -1;
	}

	// GL_COLOR_BUFFER_BIT - color buffer
	// GL_DEPTH_BUFFER_BIT - depth buffer
	// GL_STENCIL_BUFFER_BIT - stencil buffer

	glClearColor(background.R, background.G, background.B, background.A);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);

		process_events(window);
	}

	glfwTerminate();

	return 0;
}



namespace {
	void log_writer(std::ofstream& log_lw, std::string_view& log_file_name_lw, std::string_view message_lw) {
		log_lw.open(log_file_name_lw.data(), std::ios::out | std::ios::binary | std::ios::app);
		log_lw << message_lw;
		log_lw.close();
	}

	void append_title(std::string& window_title_at) {
#if defined(_WIN32) || defined(_WIN64)
		window_title_at = window_title_at + "Windows OS";
#elif defined(__APPLE__) || defined(__MACH__)
		window_title_at = window_title_at + "Mac OS";
#elif defined(linux) || defined(__linux) || defined(__linux__)
		window_title_at = window_title_at + "Linux OS";
#elif defined(unix) || defined(__unix) || defined(__unix__)
		window_title_at = window_title_at + "Unix OS";
#else
		window_title_at = window_title_at + "Unknown OS";
#endif // _WIN32 || _WIN64 OTHERS


#ifdef PROJ_VERSION_DISPL
		window_title_at = window_title_at + "  ver: " + std::to_string(VERSION_MAJOR) + '.' + std::to_string(VERSOPN_MINOR) + '.' + std::to_string(VERSION_PATCH);
#endif // PROJ_VERSION_DISPL
	}
}