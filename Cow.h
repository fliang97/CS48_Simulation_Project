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

	//Cow - Cow constructor to create a cow at a specified Tile
	//Param parentTile - The Tile in which the created cow should be located.
	//Pre - A valid tile is available and passed to this constructor.
	//Post - A cow has been created. It has parentTile and id member variables set and has incremented the Cow populationCount.
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

	//getPopulationCount - Gets the populationCount for the Cows class.
	//Return - populationCount for the Cow class.
	//Pre - TRUE
	//Post - populationCount for the Cow class has been returned.
	static int getPopulationCount();


	//modifyHealth - modifies the cow's health by some amount
	//param healthChange - the amount by which the health of the cow should be changed
	//pre - TRUE
	//post - The cow's health has been modified by the specified amount.
	void modifyHealth(int healthChange);

	//setTextureImg - Sets static_img for the Cow class to the image for the default cow sprite.
	//Pre - The cow.png image is in the project folder.
	//Post - static_img has been set for the Cow class.
	static void setTextureImg();

	//setTextureImg - Sets static_img_sick for the Cow class to the image for the sick cow sprite.
	//Pre - The cow_sick.png image is in the project folder.
	//Post - static_img_sick has been set for the Cow class.
	static void setTextureImgSick();

	//static_img - Used to store the cow.png image for the Cow class.
	static SDL_Texture *static_img;

	//static_img_sick - Used to store the cow_sick.png image for the Cow class.
	static SDL_Texture *static_img_sick;

private:

	//populationCount - The current number of Cow instances in the game.
	static int populationCount;


};
#endif /* COW_H_DEFINED */
