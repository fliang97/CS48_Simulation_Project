#ifndef ENTITY_H_DEFINED
#define ENTITY_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <vector>

using namespace std;

class Tile;

class Entity {
public:
	Entity(Tile* parentTile);

	virtual void update(vector< vector<Tile*> > *nextIterboard);
	virtual void render(int x, int y, int w, int h, SDL_Renderer* r);
	Tile* parentTile;
};

#endif /* ENTITY_H_DEFINED */
