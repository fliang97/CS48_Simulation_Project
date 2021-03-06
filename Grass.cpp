
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Game.h"
#include "Map.h"
#include "Tile.h"
#include "Entity.h"
#include "Grass.h"
#include "EntityManager.h"

using namespace std;

int Grass::populationCount = 0;

SDL_Texture* Grass::static_img = NULL;

Grass::Grass(Tile* parentTile) : Plant(parentTile) {
	id = 4;
	health = 10;
	Grass::populationCount++;
	//cout << "Grass population: " << Grass::populationCount << endl;
}

Grass::~Grass() {
	Grass::populationCount--;
	//cout << "Grass population: " << Grass::populationCount << endl;
}
/*
void Grass::update(vector< vector<Tile*> >* nextIterboard) {
	//Fix rand() to make it change.
	Tile* tile = (*nextIterboard)[parentTile->x][parentTile->y];
	if (!tile->layer1) {
		tile->layer1 = this;
		//parentTile->layer1 = NULL;
		parentTile = tile;
	}
	if (rand() % 10 == 0) {
		int x = rand() % 3 - 1;
		int y = rand() % 3 - 1;
		if (parentTile->x + x >= 0 && parentTile->x + x < static_cast<int>(nextIterboard->size())
			&& parentTile->y + y >= 0 && parentTile->y + y < static_cast<int>((*nextIterboard)[0].size())) {
			tile = (*nextIterboard)[parentTile->x + x][parentTile->y + y];
			//Square must know Entity
			if (!tile->layer1) {
				tile->layer1 = new Grass(tile);
			}
		}
	}
}
*/
void Grass::checkDeath() {
	if (health <= 0) {
		parentTile->layer1 = NULL;
		parentTile->map->toDestroyPlants.insert(this);
		//delete this;
	}
}

void Grass::checkReproduce() {
	if (rand() % 10 == 0) {
		int x = rand() % 3 - 1;
		int y = rand() % 3 - 1;
		if (parentTile->x + x >= 0 && parentTile->x + x < static_cast<int>(parentTile->map->width)
			&& parentTile->y + y >= 0 && parentTile->y + y < static_cast<int>(parentTile->map->height)) {
			Tile* s = (*parentTile->map->mapGrid)[parentTile->x + x][parentTile->y + y];
			//Square must know Entity
			EntityManager::createEntity(EntityID::grass, s);
		}
	}
}

void Grass::render(int x, int y, int w, int h, SDL_Renderer* r) {
	//SDL_Rect rect = { x, y, w, h };
	//SDL_SetRenderDrawColor(r, 0, 255, 0, 255);
	//SDL_RenderFillRect(r, &rect);

	SDL_Rect rect = { x, y, w, h };
	SDL_RenderCopy(Game::renderer, static_img, NULL, &rect);

}

int Grass::getPopulationCount() {
	return Grass::populationCount;
}

void Grass::setTextureImg() {
	//cout << "grass_1.jpg" << endl;
	Grass::static_img = IMG_LoadTexture(Game::renderer, "grass_1.jpg");
}
