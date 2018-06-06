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
	virtual ~Entity();

	//Parameters:
	//vector< vector<Tile*> >* nextIterboard: Pointer to 2d vector of Tiles. Cow changes nextIterboard to affect future actions (e.g. moving)
	//Return Values:
	//Precondition: nextIterboard is defined.
	//Postcondition: Abstract functionality
	//virtual void update(vector< vector<Tile*> > *nextIterboard);

	//Parameters:
	// x, y represent the coordinates to render at. w, h represent the width and height of the images.
	// r represents the SDL_Renderer used to render the image in the proper location.
	//Return Values:
	//Precondition: all parameters are defined.
	//Postcondition: Abstract functionality
	virtual void render(int x, int y, int w, int h, SDL_Renderer* r);

	Tile* getParentTile();
	Tile* parentTile;
	int id;
	SDL_Texture *static_img;
	int health;

	static int getPopulationCount();
	int getID();
	virtual void modifyHealth(int healthChange);


private:
	static int populationCount;


};

#endif /* ENTITY_H_DEFINED */
