#pragma once
#include "graphics\window.h"
#include "game/game.h"
#include "graphics/renderers/renderer3d.h"

namespace lord {

	class Application
	{
		graphics::Window		_window;
		game::Game				_game;
		graphics::Renderer3D	_renderer;

	public:
		Application(int width, int height, const char* title);
		void run();
	};

}