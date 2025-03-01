# Content

- [Info](#Info)
- [GLFW build](#GLFW-build)
- [Project build](#Project-build)

## Info

For this project used:

 - [GLFW](https://www.glfw.org/)
 - [GLAD2](https://gen.glad.sh/)
 - [CMake](https://cmake.org/)

[Visual Studio](https://visualstudio.microsoft.com) solution used on first commit.

Instead of [GLAD2](https://gen.glad.sh/) you can use [GLAD](https://glad.dav1d.de/).

You need change file names **gl.h** to **glad.h**, **gl.c** to **glad.c**.
In the file **glad.c** change **\#include glad/gl.h** to **\#include glad/glad.h**

## GLFW build

1. Windows

	You may need to install some dependencies.
	- x86:
	```
		cmake -S . -B ./build -A win32
		cmake --build ./build --config release
		cmake --build ./build --config debug
	```
	- x64:
	```
		cmake -S . -B ./build -A x64
		cmake --build ./build --config release
		cmake --build ./build --config debug
	```
	
2. Linux

	You may need to install some dependencies like [Wayland](https://www.glfw.org/docs/latest/compile_guide.html#compile_deps) and [X11](https://www.glfw.org/docs/latest/compile_guide.html#compile_deps) and so on.
	- x86:
	```
		cmake -S . -B ./build -D CMAKE_C_FLAGS="-m32" -D CMAKE_BUILD_TYPE="Debug"
		cmake --build ./build
		cmake -S . -B ./build -D CMAKE_C_FLAGS="-m32" -D CMAKE_BUILD_TYPE="Release"
		cmake --build ./build
	```
	- x64:
	```
		cmake -S . -B ./build -D CMAKE_C_FLAGS="-m64" -D CMAKE_BUILD_TYPE="Debug"
		cmake --build ./build
		cmake -S . -B ./build -D CMAKE_C_FLAGS="-m64" -D CMAKE_BUILD_TYPE="Release"
		cmake --build ./build
	```
	
## Project build

1. Windows

	You may need to install some dependencies like **OpenGL** and so on.
	- x86:
	```
		cmake -S . -B ./build -A win32
		cmake --build ./build --config release
		cmake --build ./build --config debug
	```
	- x64:
	```
		cmake -S . -B ./build -A x64
		cmake --build ./build --config release
		cmake --build ./build --config debug
	```

2. Linux

	You may need to install some dependencies like [OpenGL](https://en.wikibooks.org/wiki/OpenGL_Programming/Installation/Linux) and so on.
	When compiling on x86 you can get some errors like **i386 architecture of input file is incompatible with i386:x86-64 output** and so on.
	- x86:
	```
		cmake -S . -B ./build -D CMAKE_C_FLAGS="-m32" -D CMAKE_BUILD_TYPE="Debug"
		cmake --build ./build
		cmake -S . -B ./build -D CMAKE_C_FLAGS="-m32" -D CMAKE_BUILD_TYPE="Release"
		cmake --build ./build
	```
	- x64:
	```
		cmake -S . -B ./build -D CMAKE_C_FLAGS="-m64" -D CMAKE_BUILD_TYPE="Debug"
		cmake --build ./build
		cmake -S . -B ./build -D CMAKE_C_FLAGS="-m64" -D CMAKE_BUILD_TYPE="Release"
		cmake --build ./build
	```