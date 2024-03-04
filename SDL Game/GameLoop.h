#pragma once
#include "SDL.h"

using namespace std;

class GameLoop
{
public:
	GameLoop();
	~GameLoop();

	void init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);
	
	void handleEvents();
	void update();
	void render();
	void clean();

	bool running();

private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
};

