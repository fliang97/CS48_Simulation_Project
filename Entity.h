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
	// parentTile - The Tile in which the entity is currently located.
	Tile* parentTile;

	// id-  The id number of the entity that corresponds with the Entity class type.
	int id;

	//health - The current health of the entity.  Used to determine whether the entity should die.
	int health;

	//Entity - Entity constructor to create an Entity at a specified Tile
	//Param parentTile - The Tile in which the created entity should be located.
	//Pre - A valid tile is available and passed to this constructor.
	//Post - An entity has been created. It has parentTile and id member variables set and has incremented the Entity populationCount.
	Entity(Tile* parentTile);

	//~Entity - Entity destructor.
	//Pre - TRUE
	//Post - The entity's memory has been unallocated and the entity populationCount has been decremented.
	virtual ~Entity();

	//Parameters:
	//vector< vector<Tile*> >* nextIterboard: Pointer to 2d vector of Tiles. Cow changes nextIterboard to affect future actions (e.g. moving)
	//Return Values:
	//Precondition: nextIterboard is defined.
	//Postcondition: Abstract functionality
	//virtual void update(vector< vector<Tile*> > *nextIterboard);

	//Parameters:
	//Param x, y represent the coordinates to render at. w, h represent the width and height of the images.
	//Param r represents the SDL_Renderer used to render the image in the proper location.
	//Return Values:
	//Precondition: all parameters are defined.
	//Postcondition: Abstract functionality
	virtual void render(int x, int y, int w, int h, SDL_Renderer* r);

	//getParentTile - returns a pointer to the parentTile in which the calling entity resides.
	//Return - A pointer to the parentTile in which the calling entity resides.
	//Pre - TRUE
	//Post - A pointer to the parentTile in which the calling entity resides has been returned.
	Tile* getParentTile();


	//getPopulationCount - Gets the number of the calling entity type that exists in the game.
	//return - The number of some entity type that exists in the game.
	//pre - Game has been started and initialized.
	//post - The population count has been returned.
	static int getPopulationCount();

	//getID - Gets the entity ID  umber that corresponds with the calling Entity type.
	//return - The entity ID number that corresponds with the calling Entity type.
	//pre - TRUE
	//post - the entity ID has been returned.
	int getID();

	//modifyHealth - modifies the entity's health by some amount
	//param healthChange - the amount by which the health of the entity should be changed
	//pre - TRUE
	//post - The entity's health has been modified by the specified amount.
	virtual void modifyHealth(int healthChange);

private:

	//populationCount - The number of instances of entity that currently exist in the game.
	static int populationCount;

};

#endif /* ENTITY_H_DEFINED */
