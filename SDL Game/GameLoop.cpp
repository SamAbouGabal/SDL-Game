#include "GameLoop.h"


GameLoop::GameLoop()
{

}


GameLoop::~GameLoop()
{


}

void GameLoop::init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "Subsystems Initialized!" << endl;

		window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
		if (window)
		{
			cout << "Window Created!" << endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			cout << "Renderer Created!" << endl;

		}

		isRunning = true;
	}
	else
	{
		isRunning = false;
	}
}
void GameLoop::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;
	}
}

void GameLoop::update()
{

}

void GameLoop::render()
{

}

void GameLoop::clean()
{

}