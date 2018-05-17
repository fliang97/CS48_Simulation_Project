#ifndef GRASS_H_DEFINED
#define GRASS_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Tile.h"
#include "Entity.h"
using namespace std;

class Grass : public Entity {
public:
	Grass(Tile* parentTile);
	void update(vector< vector<Tile*> >* nextIterboard) override;
	void render(int x, int y, int w, int h, SDL_Renderer* r) override;
};

#endif /* GRASS_H_DEFINED */
