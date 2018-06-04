#ifndef PLANT_H_DEFINED
#define PLANT_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Map.h"
#include "Tile.h"
#include "Entity.h"
using namespace std;

class Plant : public Entity {
public:
	Plant(Tile* parentTile);
	virtual ~Plant() override;

	virtual void checkReproduce();
	virtual void checkDeath();
	int health;

	static int getPopulationCount();
private:
	static int populationCount;

};


#endif /* PLANT_H_DEFINED */
