#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>


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

	bool running() { return isRunning; }

private:
	int cnt = 0;
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
};

