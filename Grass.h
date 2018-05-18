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

	//Parameters:
	//vector< vector<Tile*> >* nextIterboard: Pointer to 2d vector of Tiles. Cow changes nextIterboard to affect future actions (e.g. moving)
	//Return Values:
	//Precondition: nextIterboard is defined.
	//Postcondition:
	//Sets Tile in current coordinates of nextIterboard to itself and sets own parentTile to that new Tile.
	//Has 1/10 chance of creating new Grass in random tile in 3x3 range centered at its own coordinates.
	//On interaction with cow, does not override cow.
	void update(vector< vector<Tile*> >* nextIterboard) override;

	//Parameters:
	// x, y represent the coordinates to render at. w, h represent the width and height of the images.
	// r represents the SDL_Renderer used to render the image in the proper location.
	//Return Values:
	//Precondition: all parameters are defined.
	//Postcondition: Image rendered at x, y with width w and height h.
	void render(int x, int y, int w, int h, SDL_Renderer* r) override;
};

#endif /* GRASS_H_DEFINED */
