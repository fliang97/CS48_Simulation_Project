
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Entity.h"
#include "Tile.h"


class Map;
using namespace std;

Tile::Tile(int x, int y, Map* map) {
		this->x = x;
		this->y = y;
		this->map = map;
		this->entity = NULL;
	}

	void Tile::update(vector< vector<Tile*> >* nextIterboard) {
		//cout << "TileUpdate" << endl;
		if (entity) entity->update(nextIterboard);
	}

	void Tile::render(int screenX, int screenY, int worldX, int worldY, int scaleX, int scaleY, SDL_Renderer* r) {
		//cout << "GameSquareRender" << endl;
		//render self
		if (entity) entity->render((screenX - worldX) + x * scaleX, (screenY - worldY) + y * scaleY, scaleX, scaleY, r); //change for zoom/scale
	}