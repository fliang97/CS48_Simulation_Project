
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Map.h"
#include "Tile.h"
#include "Entity.h"
#include "Grass.h"
using namespace std;

Grass::Grass(Tile* parentTile) : Plant(parentTile) {
	id = 4;
	health = 10;
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
			if (!s->layer1) {
				Grass* g = new Grass(s);
				parentTile->map->plants.insert(g);
				s->layer1 = g;
			}
		}
	}
}

void Grass::render(int x, int y, int w, int h, SDL_Renderer* r) {
	SDL_Rect rect = { x, y, w, h };
	SDL_SetRenderDrawColor(r, 0, 255, 0, 255);
	SDL_RenderFillRect(r, &rect);

}
