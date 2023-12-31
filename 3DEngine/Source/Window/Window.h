#pragma once

#include <iostream>

#include "../Resources/Graphics.h"

struct GLFWwindow;

class Window {
public:
	static int width;
	static int height;
	static GLFWwindow* window;
	static int initialize(int width, int height, const char* title);
	static void terminate();

	static void setCursorMode(int mode);
	static bool isShouldClose();
	static void setShouldClose(bool flag);
	static void swapBuffers();
};
