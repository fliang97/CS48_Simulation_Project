#ifndef TILE_H_DEFINED
#define TILE_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Entity.h"


class Map;
using namespace std;

class Tile{ //will extend components
public:
	Tile(int x, int y, Map* map) {
		this->x = x;
		this->y = y;
		this->map = map;
		this->entity = NULL;
	}

	void update(vector< vector<Tile*> >* nextIterboard) {
	    //cout << "TileUpdate" << endl;
	    if (entity) entity->update(nextIterboard);
	}

	void render(int screenX, int screenY, int worldX, int worldY, int scaleX, int scaleY, SDL_Renderer* r) {
	    //cout << "GameSquareRender" << endl;
	    //render self
	    if (entity) entity->render((screenX - worldX) + x * scaleX, (screenY - worldY) + y * scaleY, scaleX, scaleY, r); //change for zoom/scale
	}

	Entity* entity; //change to multiple layers
	int x;
	int y;
	Map* map;
};

#endif /* TILE_H_DEFINED */
