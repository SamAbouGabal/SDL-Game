#include "GameLoop.h"
#include "TextureManager.h"
#include "TileMap.h"
#include "Components.h"
#include "Vector2D.h"
#include "Collision.h"

TileMap* tileMap;

SDL_Renderer* GameLoop::renderer = nullptr;
SDL_Event GameLoop::event;

vector<ColliderComponent*> GameLoop::colliders;

Manager manager;
auto& player(manager.addEntity());
auto& wall(manager.addEntity());

GameLoop::GameLoop()
{

}


GameLoop::~GameLoop()
{


}

void GameLoop::init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "Subsystems Initialized!" << endl;

		window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
		if (window)
		{
			cout << "Window Created!" << endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			cout << "Renderer Created!" << endl;

		}

		isRunning = true;
	}
	else
	{
		isRunning = false;
	}


	player.addComponent<TransformComponent>(2);
	player.addComponent<SpriteComponent>("assets/Player.png");
	player.addComponent<KeyboardController>();
	player.addComponent<ColliderComponent>("player");


	tileMap = new TileMap();
	wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
	wall.addComponent<SpriteComponent>("assets/Dirt.png");
	wall.addComponent<ColliderComponent>("wall");
}

void GameLoop::handleEvents()
{
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;
	}
}

void GameLoop::update()
{
	manager.refresh();
	manager.update();
	
	if (Collision::AABB(player.getComponent<ColliderComponent>().collider, wall.getComponent<ColliderComponent>().collider)) {
		player.getComponent<TransformComponent>().scale = 1;
		player.getComponent<TransformComponent>().velocity * -1;
		cout << "Wall Hit!" << endl;
	}
	
}

void GameLoop::render()
{
	SDL_RenderClear(renderer);
	tileMap->DrawTileMap();
	manager.draw();
	SDL_RenderPresent(renderer);
}

void GameLoop::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Game Cleaned!" << endl;
}