#include "SDL.h"
#include "GameLoop.h"

using namespace std;

GameLoop* gameLoop = nullptr;

int main(int argc, char* argv[]) 
{
	gameLoop = new GameLoop();
	gameLoop->init("GameEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (gameLoop->running())
	{
		gameLoop->handleEvents();
		gameLoop->update();
		gameLoop->render();

	}

	gameLoop->clean();

	return 0;
}