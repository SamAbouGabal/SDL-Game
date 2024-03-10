#pragma once
#include "Components.h"
#include "ECS.h"
#include "TransformComponent.h"
#include "SDL.h"

class TileComponent : public Component
{
public:
	TransformComponent* transform;
	SpriteComponent* sprite;

	SDL_Rect tileRect;
	int tileID;
	const char* path; // remove const??

	TileComponent() = default;

	TileComponent(int x, int, y, int w, int h, int id){

		tileRect.x = x;
		tileRect.y = y;
		tileRect.w = w;
		tileRect.h = h;
		tileID = id;

		switch (tileID)
		{
		case 0:
			path = "assets/Water.png";
			break;
		case 1:
			path = "assets/Dirt.png";
			break;
		case 2:
			path = "assets/Grass.png";
			break;
		default:
			break;
		}
	}

	void init() override {

		entity->addComponent<TransformComponent>(tileRect.x, tileRect.y, tileRect.w, tileRect.h, 1);
		transform = &entity->getComponent<TransformComponent>();

		entity->addComponent<SpriteComponent>(path);
		sprite = &entity->getComponent<SpriteComponent>();
	}
};