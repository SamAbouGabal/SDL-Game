#include "SDL.h"
#include "GameLoop.h"

using namespace std;

GameLoop* gameLoop = nullptr;

int main(int argc, char* argv[]) 
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	gameLoop = new GameLoop();
	gameLoop->init("GameEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (gameLoop->running())
	{
		frameStart = SDL_GetTicks();

		gameLoop->handleEvents();
		gameLoop->update();
		gameLoop->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	gameLoop->clean();

	return 0;
}