#include "application.h"
#include <SDL/SDL.h>
#include <iostream>

int main(int argc, char** argv)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "[ERROR] Could not init SDL!" << std::endl;
	}
	else
	{
		lord::Application app(1920, 1080, "Lord0");
		app.run();
	}
	SDL_Quit();
	std::cout << "Press enter to exit program..." << std::endl;
	std::cin.get();
	return 0;
}