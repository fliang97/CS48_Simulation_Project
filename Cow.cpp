
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//#include <iostream>
//#include <vector>
//#include <cstdlib>

//#include "Map.h"
//#include "Tile.h"
//#include "Entity.h"
#include "Cow.h"

using namespace std;


//PUBLIC FUNCTIONS

Cow::Cow(Tile* parentTile) : Entity(parentTile) { }

void Cow::update(vector< vector<Tile*> >* nextIterboard) {
	//cout << "CowUpdate" << endl;
	Tile* s = (*nextIterboard)[parentTile->x][parentTile->y];
	int x = rand() % 3 - 1;
	int y = rand() % 3 - 1;
	if (parentTile->x + x >= 0 && parentTile->x + x < static_cast<int>(nextIterboard->size())
		&& parentTile->y + y >= 0 && parentTile->y + y < static_cast<int>((*nextIterboard)[0].size())) {
		s = (*nextIterboard)[parentTile->x + x][parentTile->y + y];//getting tentative location in iter
		//Square must know Entity
		s->entity = this; //setting iterboard tile entity to this
		parentTile->entity = NULL; // old tile parent in old board to null
		parentTile = s; // set parent to new tile
	}
	else {
		Tile* tile = (*nextIterboard)[parentTile->x][parentTile->y];  //if it cant move then just update new board with old lcoation
		//Square must know Entity
		//if (!tile->entity) //gets overriden if something moves into it. This now overrides anything on it.
		tile->entity = this;
		parentTile->entity = NULL;
		parentTile = tile;
	}
}

void Cow::render(int x, int y, int w, int h, SDL_Renderer* r) {
	//cout << "GrassRender" << endl;
	//SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
	SDL_Rect rect = { x, y, w, h };
	//SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0x00));
	SDL_SetRenderDrawColor(r, 100, 50, 0, 255);
	SDL_RenderFillRect(r, &rect);
	//SDL_RenderPresent( renderer);
}