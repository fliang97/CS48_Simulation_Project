///Unnecessary includes:
//#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
//#include <iostream>
///#include <vector>
//#include <cstdlib>
//#include "Tile.h"

#include "Entity.h"
class Tile;

using namespace std;


//PUBLIC FUNCTIONS

Entity::Entity(Tile* parentTile) {
	this->parentTile = parentTile;
	id = 0;
}
//don't move
/*
void Entity::update(vector< vector<Tile*> >* nextIterboard) {
	//cout << "EntityUpdate" << endl;
	//(*nextIterboard)[parentTile->x][parentTile->y]->entity = new Entity((*nextIterboard)[parentTile->x][parentTile->y]);
}
*/
void Entity::render(int x, int y, int w, int h, SDL_Renderer* r) {
}
