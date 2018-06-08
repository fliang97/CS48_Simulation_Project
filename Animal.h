#ifndef ANIMAL_H_DEFINED
#define ANIMAL_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include "Map.h"
#include "Tile.h"
#include "Entity.h"

using namespace std;

class Animal : public Entity {
public:
	//health - The health of the Animal.
	int health;

	//hunger - The hunger of the Animal.
	int hunger;

	//age - The age of the Animal which corresponds with the number of game updates in which it has existed.
	int age;

	//ageMax - The maximum age of the animal, above which the animal will die.
	int ageMax;

	//Animal - Animal constructor to create an Animal at a specified Tile
	//Param parentTile - The Tile in which the created animal should be located.
	//Pre - A valid tile is available and passed to this constructor.
	//Post - An entity has been created. It has parentTile, id, ageMax member variables set and has incremented the Animal populationCount.
	Animal(Tile* parentTile);


	//~Animal - Animal destructor.
	//Pre - TRUE
	//Post - The animals's memory has been unallocated and the Animal class populationCount has been decremented.
	virtual ~Animal() override;


	//checkMove - moves the animal to an adjacent, open square.  It will move towards food if it's nearby, otherwise it will wander randomly.
	//pre TRUE
	//post The animal is on a square that is in the map bounds and isn't overlapping with another annimal.
	virtual void checkMove();


	//checkAction - Checks the animal's current status and location and then makes actions accordingly
	//Pre - TRUE
	//Post - The animals's age and hunger is incremented.  If the animal near food and hungry then the animal eats the food.
	virtual void checkAction();


	//checkDeath - Checks the entity's current status and adds it to a list of to remove entities if conditions are met.
	//Pre - TRUE
	//Post - The entity's health is decreased if very hungry.  If health is negative or age is past maxAge, add entity to removal list.
	virtual void checkDeath();

	//checkReproduce - Creates a new Animal in an adjacent square if conditions are met.
	//Pre - TRUE
	//Post - If age and hunger requirements are met, randomly create a new Aniaml in an adjacent Tile.
	virtual void checkReproduce();

	//getPopulation - Gets the populationCount for the Animal class.
	//Return - The populationCount for the Animal class.
	//Pre - TRUE
	//Post - The populationCount for the Animal class has been returned.
	static int getPopulationCount();


private:
	// The number of Animal instances currently in the game.
	static int populationCount;
};


#endif /* ANIMAL_H_DEFINED */
