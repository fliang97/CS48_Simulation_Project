
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

Grass::Grass(Tile* parentTile) : Entity(parentTile) { }

void Grass::update(vector< vector<Tile*> >* nextIterboard) {
	//Fix rand() to make it change.
	Tile* tile = (*nextIterboard)[parentTile->x][parentTile->y];
	if (!tile->entity) {
		tile->entity = this;
		parentTile->entity = NULL;
		parentTile = tile;
	}
	if (rand() % 10 == 0) {
		int x = rand() % 3 - 1;
		int y = rand() % 3 - 1;
		if (parentTile->x + x >= 0 && parentTile->x + x < static_cast<int>(nextIterboard->size())
			&& parentTile->y + y >= 0 && parentTile->y + y < static_cast<int>((*nextIterboard)[0].size())) {
			tile = (*nextIterboard)[parentTile->x + x][parentTile->y + y];
			//Square must know Entity
			if (!tile->entity) {
				tile->entity = new Grass(tile);
			}
		}
	}
}

void Grass::render(int x, int y, int w, int h, SDL_Renderer* r) {
	SDL_Rect rect = { x, y, w, h };

	SDL_SetRenderDrawColor(r, 0, 255, 0, 255);
	SDL_RenderFillRect(r, &rect);

}
