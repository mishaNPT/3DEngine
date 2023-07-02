#pragma once

#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>

#include <string>

#include "../Resources/Graphics.h"
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

class Shader {
public:
	unsigned int id;

	Shader(unsigned int id);
	~Shader();

	void use();

	void uniformMatrix(std::string name, glm::mat4 matrix);
	void uniformInt(std::string name, int value);
	void uniformBool(std::string name, bool value);
	void uniformVec2(std::string name, glm::vec2 vector);
	void uniformVec3(std::string name, glm::vec3 vector);
	void uniformVec4(std::string name, glm::vec4 vector);
};

extern Shader* load_shader(std::string vertexFile, std::string fragmentFile);
