
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
	//cout << "GrassUpdate" << endl;
	//Fix rand() to make it change.
	Tile* tile = (*nextIterboard)[parentTile->x][parentTile->y];
	if (!tile->entity) {
		tile->entity = this;
		parentTile->entity = NULL;
		parentTile = tile;
	}
	if (rand() % 10 == 0) {
		//cout << "Time to spread" << endl;
		int x = rand() % 3 - 1;
		int y = rand() % 3 - 1;
		if (parentTile->x + x >= 0 && parentTile->x + x < static_cast<int>(nextIterboard->size())
			&& parentTile->y + y >= 0 && parentTile->y + y < static_cast<int>((*nextIterboard)[0].size())) {
			//cout << "Time to spread20" << endl;
			tile = (*nextIterboard)[parentTile->x + x][parentTile->y + y];
			//cout << "Time to spread2" << endl;
			//Square must know Entity
			if (!tile->entity) {
				tile->entity = new Grass(tile);
				//cout << "Time to spread3" << endl;
			}
		}
	}
}

void Grass::render(int x, int y, int w, int h, SDL_Renderer* r) {
	//cout << "GrassRender" << endl;
	//SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
	SDL_Rect rect = { x, y, w, h };
	//SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0x00));
	SDL_SetRenderDrawColor(r, 0, 255, 0, 255);
	SDL_RenderFillRect(r, &rect);
	//SDL_RenderPresent( renderer);
}
