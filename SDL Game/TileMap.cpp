#include "TileMap.h"
#include "GameLoop.h"
#include <fstream>


TileMap::TileMap()
{

}

TileMap::~TileMap() {


}

void TileMap::LoadTileMap(std::string path, int sizeX, int sizeY)
{
	char tile;
	std::fstream mapFile;
	mapFile.open(path);

	for (int y = 0; y < sizeY; y++) {

		for (int x = 0; x < sizeX; x++) {

			mapFile.get(tile);
			GameLoop::AddTile(atoi(&tile), x * 32, y * 32);
			mapFile.ignore();
		}
	}

	mapFile.close();

}
