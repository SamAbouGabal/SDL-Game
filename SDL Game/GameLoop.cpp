#include "GameLoop.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "TileMap.h"
#include "ECS.h"
#include "Components.h"

GameObject* player;
GameObject* enemy;
TileMap* tileMap;

SDL_Renderer* GameLoop::renderer = nullptr;

Manager manager;
auto& newPlayer(manager.addEntity());

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

	player = new GameObject("assets/Player.png", 0, 0);
	enemy = new GameObject("assets/Enemy.png", 50, 50);
	tileMap = new TileMap();
	newPlayer.addComponent<PositionComponent>();
	newPlayer.getComponent<PositionComponent>().setPos(500, 500);
}

void GameLoop::handleEvents()
{
	SDL_Event event;
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
	player->Update();
	enemy->Update();
	manager.update();
	cout << newPlayer.getComponent<PositionComponent>().x() << "," <<
		newPlayer.getComponent<PositionComponent>().y() << endl;
	
}

void GameLoop::render()
{
	SDL_RenderClear(renderer);
	tileMap->DrawTileMap();
	player->Render();
	enemy->Render();
	SDL_RenderPresent(renderer);
}

void GameLoop::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Game Cleaned!" << endl;
}