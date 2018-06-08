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
	
	//health - The health of the plant that is checked to determine if the Plant should be removed.
	int health;

	//Plant - Plant constructor to create a Plant at a specified Tile
	//Param parentTile - The Tile in which the created Plant should be located.
	//Pre - A valid tile is available and passed to this constructor.
	//Post - A Plant has been created. It has parentTile and id member variables set and has incremented the Plant populationCount.
	Plant(Tile* parentTile);

	//~Plant - Plant destructor.
	//Pre - TRUE
	//Post - The plant's memory has been unallocated and the Plant class populationCount has been decremented.
	virtual ~Plant() override;

	//checkReproduce - With random chance, creates a plant in an adjacent open Tile to the calling plant.
	//Pre - The calling plant has been properly associated with a Tile.
	//Post - If an open Tile was randomly selected, a new plant has been created in an adjacent Tile to calling plant.
	virtual void checkReproduce();

	//checkDeath - Checks the Plant's current status and adds it to a list of to remove Plants if conditions are met.
	//Pre - TRUE
	//Post - If health is negative, add plant to removal list.
	virtual void checkDeath();

	//getPopulationCount - Gets the populationCount for the Plant class.
	//Return - populationCount for the Plant class.
	//Pre - TRUE
	//Post - populationCount for the Plant class has been returned.
	static int getPopulationCount();

private:

	//populationCount - The current number of Grass instances in the game.
	static int populationCount;

};

#endif /* PLANT_H_DEFINED */
