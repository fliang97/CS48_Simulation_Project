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

int Entity::populationCount = 0;

//PUBLIC FUNCTIONS

Entity::Entity(Tile* parentTile) {
	this->parentTile = parentTile;
	id = 0; // Number that corresponds with the Entity class type.
	Entity::populationCount++;
}

Entity::~Entity() {
	populationCount--;
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

Tile* Entity::getParentTile() {
	return this->parentTile;
}

int Entity::getPopulationCount() {
	return Entity::populationCount;
}

int Entity::getID() {
	return id;
}

void Entity::modifyHealth(int healthChange) {
	return;
}