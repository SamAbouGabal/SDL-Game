#pragma once
#include "GameLoop.h"

class TextureManager {

public:
	static SDL_Texture* LoadTexture(const char* fileName);
};