#pragma once
#include "GameLoop.h"

class TileMap
{
public:

	TileMap();
	~TileMap();

	void LoadTileMap();
	void DrawTileMap();

private:

	SDL_Rect src, dest;

	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;

	int map[20][25];
};