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

Instead of [GLAD2](https://gen.glad.sh/) you can use [GLAD](https://glad.dav1d.de/)

## GLFW build

1. Windows
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
	
## Project build

1. Windows
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