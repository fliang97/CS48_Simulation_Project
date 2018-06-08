#ifndef COW_H_DEFINED
#define COW_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

#include "Map.h"
#include "Tile.h"
#include "Animal.h"
using namespace std;

class Cow : public Animal {
public:
	Cow(Tile* parentTile);
	~Cow() override;
	//Parameters:
	//vector< vector<Tile*> >* nextIterboard: Pointer to 2d vector of Tiles. Cow changes nextIterboard to affect future actions (e.g. moving)
  //Return Values:
  //Precondition: nextIterboard is defined.
  //Postcondition:
	//Sets a random Tile in 3x3 array around center to point to itself, if possible.
	//On interaction with grass, overrides grass.
	//Sets this parentTile to that new Tile.
	//void update(vector< vector<Tile*> >* nextIterboard) override;

	//Parameters:
	// x, y represent the coordinates to render at. w, h represent the width and height of the images.
	// r represents the SDL_Renderer used to render the image in the proper location.
	//Return Values:
	//Precondition: all parameters are defined.
	//Postcondition: Image rendered at x, y with width w and height h.

	void render(int x, int y, int w, int h, SDL_Renderer* r) override;

	//checkMove - moves the Cow to an adjacent, open square.  It will move towards food if it's nearby, otherwise it will wander randomly.
	//pre TRUE
	//post The cow is on a square that is in the map bounds and isn't overlapping with another annimal.
	void checkMove() override;


	void checkAction() override;
	void checkDeath() override;
	void checkReproduce() override;
	static int getPopulationCount();
	void modifyHealth(int healthChange);

	static void setTextureImg();
	static void setTextureImgSick();

	static SDL_Texture *static_img;
	static SDL_Texture *static_img_sick;

private:
	static int populationCount;


};
#endif /* COW_H_DEFINED */
