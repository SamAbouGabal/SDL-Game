#pragma once
#include "SDL.h"
#include "ColliderComponent.h"
class ColliderComponent;

class Collision {
public:
	static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB); //Axis Alligned Binding Box

	static bool AABB(const ColliderComponent& colA, const ColliderComponent& colB);

};