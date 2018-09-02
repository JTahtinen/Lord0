#pragma once
#include <SDL/SDL.h>
#include <GL/glew.h>

namespace lord { namespace graphics {

	class Window
	{
		SDL_Window*			_window;
		SDL_GLContext		_glContext;
		int					_width;
		int					_height;
	public:
		Window(int width, int height, const char* title);
		~Window();
		void setClearColor(GLclampf r, GLclampf g, GLclampf b);
		void clear();
		void update();
		inline int getWidth() const { return _width; }
		inline int getHeight() const { return _height; }
	};

}}