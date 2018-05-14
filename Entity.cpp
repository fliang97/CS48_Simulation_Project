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

Entity::Entity(Tile* parentSquare) {
	this->parentSquare = parentSquare;
}
//don't move
void Entity::update(vector< vector<Tile*> >* nextIterboard) {
	//cout << "EntityUpdate" << endl;
	//(*nextIterboard)[parentSquare->x][parentSquare->y]->e = new Entity((*nextIterboard)[parentSquare->x][parentSquare->y]);
}
void Entity::render(int x, int y, int w, int h, SDL_Renderer* r) {
	//cout << "EntityRender" << endl;
	//cout << "Entity" << endl;
}