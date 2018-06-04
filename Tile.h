#ifndef TILE_H_DEFINED
#define TILE_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <cstdlib>

#include "Entity.h"

class Map;
using namespace std;

class Tile{ //will extend components
public:
	Tile(int x, int y, Map* map);
	//void update(vector< vector<Tile*> >* nextIterboard);
	void render(int screenX, int screenY, int worldX, int worldY, int scaleX, int scaleY, SDL_Renderer* r);

	Entity* layer1; //Terrain
	Entity* layer2; //Object
	int x;
	int y;
	Map* map;

	Entity* getEntity(int layerNum);

};

#endif /* TILE_H_DEFINED */
