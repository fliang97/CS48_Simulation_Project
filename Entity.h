#ifndef ENTITY_H_DEFINED
#define ENTITY_H_DEFINED

///Unnecessary includes:
//#include <cstdlib>
//#include "GameSquare.h"


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//#include <SDL.h>

#include <iostream>
#include <vector>

class GameSquare;

using namespace std;

class Entity {
public:
	Entity(GameSquare* parentSquare);

	virtual void update(vector< vector<GameSquare*> > *nextIterboard);
	virtual void render(int x, int y, int w, int h, SDL_Renderer* r);
	GameSquare* parentSquare;
};

#endif /* ENTITY_H_DEFINED */
