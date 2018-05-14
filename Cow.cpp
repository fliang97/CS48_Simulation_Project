
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//#include <iostream>
//#include <vector>
//#include <cstdlib>

//#include "GameState.h"
//#include "Tile.h"
//#include "Entity.h"
#include "Cow.h"

using namespace std;


//PUBLIC FUNCTIONS

Cow::Cow(Tile* parentSquare) : Entity(parentSquare) { }

void Cow::update(vector< vector<Tile*> >* nextIterboard) {
	//cout << "CowUpdate" << endl;
	Tile* s = (*nextIterboard)[parentSquare->x][parentSquare->y];
	int x = rand() % 3 - 1;
	int y = rand() % 3 - 1;
	if (parentSquare->x + x >= 0 && parentSquare->x + x < static_cast<int>(nextIterboard->size())
		&& parentSquare->y + y >= 0 && parentSquare->y + y < static_cast<int>((*nextIterboard)[0].size())) {
		s = (*nextIterboard)[parentSquare->x + x][parentSquare->y + y];
		//Square must know Entity
		s->e = this;
		parentSquare->e = NULL;
		parentSquare = s;
	}
	else {
		Tile* s = (*nextIterboard)[parentSquare->x][parentSquare->y];
		//Square must know Entity
		//if (!s->e) //gets overriden if something moves into it. This now overrides anything on it.
		s->e = this;
		parentSquare->e = NULL;
		parentSquare = s;
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