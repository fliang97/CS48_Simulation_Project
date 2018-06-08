#ifndef WOLF_H_DEFINED
#define WOLF_H_DEFINED

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

class Wolf : public Animal {
public:

	//static_img - Used to store the wolf.png image for the Cow class.
	static SDL_Texture *static_img;

	//static_img - Used to store the wolf_sick.png image for the Cow class.
	static SDL_Texture *static_img_sick;

	//Wolf - Wolf constructor to create a wolf at a specified Tile
	//Param parentTile - The Tile in which the created wolf should be located.
	//Pre - A valid tile is available and passed to this constructor.
	//Post - A wolf has been created. It has parentTile and id member variables set and has incremented the Wolf populationCount.
	Wolf(Tile* parentTile);

	//~Wolf - Wolf destructor.
	//Pre - TRUE
	//Post - The wolf's memory has been unallocated and the Wolf class populationCount has been decremented.
	~Wolf() override;

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

	//checkMove - moves the Wolf to an adjacent, open square.  It will move towards food if it's nearby, otherwise it will wander randomly.
	//pre TRUE
	//post The wolf is on a square that is in the map bounds and isn't overlapping with another animal.
	void checkMove() override;

	//checkAction - Checks the wolf's current status and location and then makes actions accordingly
	//Pre - TRUE
	//Post - The wolf's age and hunger is incremented.  If the wolf is in an adjacent Tile to a cow and is hungry then the wolf ate the cow.
	void checkAction() override;

	//checkDeath - Checks the wolf's current status and adds it to a list of to remove entities if conditions are met.
	//Pre - TRUE
	//Post - The wolf's health is decreased if very hungry.  If health is negative or age is past maxAge, add wolf to removal list.
	void checkDeath() override;

	//checkReproduce - Creates a new wolf in an adjacent square if conditions are met.
	//Pre - TRUE
	//Post - If age and hunger requirements are met, randomly create a new wolf in an adjacent Tile.
	void checkReproduce() override;

	//modifyHealth - modifies the wolf's health by some amount
	//param healthChange - the amount by which the health of the wolf should be changed
	//pre - TRUE
	//post - The wolf's health has been modified by the specified amount.
	void modifyHealth(int healthChange) override;

	//setTextureImg - Sets static_img for the Wolf class to the image for the default wolf sprite.
	//Pre - The wolf.png image is in the project folder.
	//Post - static_img has been set for the Wolf class.
	static void setTextureImg();

	//setTextureImg - Sets static_img_sick for the Wolf class to the image for the sick wolfS sprite.
	//Pre - The wolf_sick.png image is in the project folder.
	//Post - static_img_sick has been set for the Wolf class.
	static void setTextureImgSick();

	//getPopulationCount - Gets the populationCount for the Wolf class.
	//Return - populationCount for the Wolf class.
	//Pre - TRUE
	//Post - populationCount for the Wolf class has been returned.
	static int getPopulationCount();


private:

	//populationCount - The current number of Wolf instances in the game.
	static int populationCount;
};
#endif /* WOLF_H_DEFINED */
