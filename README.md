# Content

- [Info](#info)

## Info

For this project used:

 - [GLFW](https://www.glfw.org/)
 - [GLAD](https://glad.dav1d.de/)

Instead of [GLAD](https://glad.dav1d.de/) you can use [GLAD2](https://gen.glad.sh/)

[GLFW](https://www.glfw.org/) build command:

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