/* Opening basic libs */
#include <iostream>
// #include <thread>
/////////////////////////

/* Opening glfw and glew */
#include "../Resources/Graphics.h"
///////////////////////////

/* glm */
#include "glm/glm.hpp"
#include "glm/ext.hpp"
using namespace glm;
/////////
 
/* Opening my systems */
#include "Window/Window.h"
#include "Window/Events.h"
#include "Window/Camera.h"
#include "Graphics/Mesh.h"
#include "Graphics/Shader.h"
#include "Graphics/Texture.h"
#include "Objects/Plane.h"
#include "Objects/Cube.h"
#include "Objects/BigCube.h"
////////////////////////

/*     Constants     */
const int Width = 1280;
const int Height = 960;

bool texturing = false;  // use texture or not

float lastTime = (float)glfwGetTime();
float delta = 0.0f;
///////////////////////

int main() {
	// Create Window
	if (Window::initialize(Width, Height, "MyEngine") != 0) {
		std::cerr << "Failed to initialize Window" << std::endl;
		return -1;
	}

	// Create Events
	if (Events::initialize() != 0) {
		std::cerr << "Failed to initialize Events" << std::endl;
		Window::terminate();
		return -1;
	}
	
	//Create Shaders
	Shader* shader = load_shader("../3DEngine/Resources/ShaderFiles/VertexShader.vert", "../3DEngine/Resources/ShaderFiles/FragmentShader.frag");
	if (shader == nullptr) {
		std::cerr << "Failed to load shader" << std::endl;
		Window::terminate();
		Events::terminate();
		return -1;
	}

	// Create Camera
	Camera* camera = new Camera(vec3(0, 0, 1), radians(60.0f));

	// Create Objects
	Cube* cube1 = new Cube(0.0f, 0.0f, 0.0f, 1.0f, vec3(0.7f, 0.3f, 0.3f), "../3DEngine/Resources/TextureFiles/stone.jpg");
	Cube* cube = new Cube(2.2f, 0.0f, 0.0f, 1.0f, vec3(0.3f, 0.7f, 0.3f), "../3DEngine/Resources/TextureFiles/cristmasTree.png", true);
	Cube* cube3 = new Cube(-2.2f, 0.0f, 0.0f, 1.0f, vec3(0.3f, 0.3f, 0.7f), "../3DEngine/Resources/TextureFiles/cat.jpg");
	//Plane* plane = new Plane(0.0f, 0.0f, 0.0f, 5.0f, 3.0f, vec3(0.8f, 0.6f, 0.3f), "../3DEngine/Resources/TextureFiles/cat.jpg");

	glClearColor(0.0f, 0.0f, 0.0f, 1);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glEnable(GL_FRAMEBUFFER_SRGB);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	while (!Window::isShouldClose()) {
		float currentTime = (float)glfwGetTime();
		delta = currentTime - lastTime;
		lastTime = currentTime;

		if (Events::jpressed(GLFW_KEY_ESCAPE)) {
			Window::setShouldClose(true);
		}
		if (Events::jpressed(GLFW_KEY_TAB)) {
			Events::toogleCursor();
		}

		if (Events::jpressed(GLFW_KEY_T)) {
			texturing = !texturing;
		}

		if (Events::pressed(GLFW_KEY_LEFT_SHIFT)) {
			camera->speed = 9.0f;
		}
		else {
			camera->speed = 5.0f;
		}

		if (Events::pressed(GLFW_KEY_W)) {
			camera->position += camera->front * delta * camera->speed;
		}
		if (Events::pressed(GLFW_KEY_S)) {
			camera->position -= camera->front * delta * camera->speed;
		}
		if (Events::pressed(GLFW_KEY_D)) {
			camera->position += camera->right * delta * camera->speed;
		}
		if (Events::pressed(GLFW_KEY_A)) {
			camera->position -= camera->right * delta * camera->speed;
		}

		if (Events::_cursor_locked) {
			camera->camY += -Events::deltaY / Window::height;
			camera->camX += -Events::deltaX / Window::height;

			if (camera->camY < -radians(90.0f)) {
				camera->camY = -radians(90.0f);
			}
			if (camera->camY > radians(90.0f)) {
				camera->camY = radians(90.0f);
			}

			camera->rotation = mat4(1.0f);
			camera->rotate(camera->camY, camera->camX, 0);
		}

		// Draw
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shader->use();
		shader->uniformMatrix("model", camera->model);
		shader->uniformMatrix("projview", camera->getProjection() * camera->getView());
		shader->uniformBool("isTextured", texturing);

		cube1->renderCube();
		cube->renderCube();
		cube3->renderCube();
		//plane->renderPlane();

		Window::swapBuffers();
		Events::pullEvents();
	}

	// Closing systems
	delete shader;
	delete camera;

	delete cube1;
	delete cube;
	delete cube3;
	//delete plane;

	Window::terminate();
	Events::terminate();
	
	return 0;
}
