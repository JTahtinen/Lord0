#include "window.h"
#include "../defs.h"
#include <GL\glew.h>
#include <iostream>

namespace lord { namespace graphics {
	
	Window::Window(int width, int height, const char* title)
		: _width(width)
		, _height(height)
	{
		Uint32 sdlVideoInit = SDL_WasInit(SDL_INIT_VIDEO);
		if (!sdlVideoInit)
		{
			SDL_Init(SDL_INIT_VIDEO);
		}

		SDL_ShowCursor(SDL_DISABLE);
		SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

		_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
		_glContext = SDL_GL_CreateContext(_window);
		//SDL_GL_SetSwapInterval(1);
		GLenum status = glewInit();

		if (status != GLEW_OK)
		{
			std::cerr << "Glew failed to initialize!" << std::endl;
		}

		GLCALL(glEnable(GL_DEPTH_TEST));
		GLCALL(glEnable(GL_CULL_FACE));
		GLCALL(glCullFace(GL_BACK));
		GLCALL(glDepthFunc(GL_LESS));

		setClearColor(0.3f, 0.1f, 0.8f);
	}

	Window::~Window()
	{
		SDL_GL_DeleteContext(_glContext);
		SDL_DestroyWindow(_window);
	}

	void Window::setClearColor(GLclampf r, GLclampf g, GLclampf b)
	{
		glClearColor(r, g, b, 1.0f);
	}

	void Window::clear()
	{
		glClear(GL_DEPTH_BUFFER_BIT);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Window::update()
	{
		SDL_SetRelativeMouseMode(SDL_TRUE);
		SDL_GL_SwapWindow(_window);
	}
}}