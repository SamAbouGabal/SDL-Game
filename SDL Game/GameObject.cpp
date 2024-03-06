#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* textureSheet, SDL_Renderer* ren) {

	renderer = ren;
	objTexture = TextureManager::LoadTexture(textureSheet, ren);

}

void GameObject::Update() {

	xPos = 0;
	xPos = 0;

	srcRect.h = 32;
	srcRect.w = 32;

}

void GameObject::Render() {

	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}
