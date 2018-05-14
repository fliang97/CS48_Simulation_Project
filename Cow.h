#ifndef COW_H_DEFINED
#define COW_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <vector>
#include <cstdlib>

#include "GameState.h"
#include "Tile.h"
#include "Entity.h"
using namespace std;

class Cow : public Entity {
public:
	Cow(Tile* parentSquare);
	void update(vector< vector<Tile*> >* nextIterboard) override;
	void render(int x, int y, int w, int h, SDL_Renderer* r) override;

};
#endif /* COW_H_DEFINED */
