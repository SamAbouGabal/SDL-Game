#pragma once
#include "GameLoop.h"

class TileMap
{
public:

	TileMap();
	~TileMap();

	void LoadTileMap(int arr[20][25]);
	void DrawTileMap();

private:

	SDL_Rect src, dest;

	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;

	int map[20][25];
};