#pragma once

#include <iostream>
#include <string>

#include "../../Resources/Graphics.h"

class Texture {
private:
	unsigned int id;
	int _width, _height;

public:
	Texture(std::string textureFile, unsigned int number);  // 0 - .jpg, 1 - .png
	~Texture();

	void bind();
};

