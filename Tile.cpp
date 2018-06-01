
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
		this->layer1 = NULL;
		this->layer2 = NULL;
	}
/*
	void Tile::update(vector< vector<Tile*> >* nextIterboard) {
		//cout << "TileUpdate" << endl;
		//if (layer1) layer1->update(nextIterboard);
		//if (layer2) layer2->update(nextIterboard);
	}
*/
	void Tile::render(int screenX, int screenY, int worldX, int worldY, int scaleX, int scaleY, SDL_Renderer* r) {
		//render self
		if (layer1) layer1->render((screenX - worldX) + x * scaleX, (screenY - worldY) + y * scaleY, scaleX, scaleY, r);
		if (layer2) layer2->render((screenX - worldX) + x * scaleX, (screenY - worldY) + y * scaleY, scaleX, scaleY, r);
	}
