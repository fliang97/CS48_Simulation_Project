#ifndef GRASS_H_DEFINED
#define GRASS_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Tile.h"
#include "Plant.h"
using namespace std;

class Grass : public Plant {
public:
	
	//static_img - Used to store the grass_1.png image for the Grass class.
	static SDL_Texture *static_img;

	//Grass - Grass constructor to create a Grass at a specified Tile
	//Param parentTile - The Tile in which the created Grass should be located.
	//Pre - A valid tile is available and passed to this constructor.
	//Post - A Grass has been created. It has parentTile, id, health member variables set and has incremented the Grass populationCount.
	Grass(Tile* parentTile);

	//~Grass - Grass destructor.
	//Pre - TRUE
	//Post - The grass's memory has been unallocated and the Grass class populationCount has been decremented.
	virtual ~Grass() override;

	//Parameters:
	//vector< vector<Tile*> >* nextIterboard: Pointer to 2d vector of Tiles. Cow changes nextIterboard to affect future actions (e.g. moving)
	//Return Values:
	//Precondition: nextIterboard is defined.
	//Postcondition:
	//Sets Tile in current coordinates of nextIterboard to itself and sets own parentTile to that new Tile.
	//Has 1/10 chance of creating new Grass in random tile in 3x3 range centered at its own coordinates.
	//On interaction with cow, does not override cow.
	//void update(vector< vector<Tile*> >* nextIterboard) override;

	//Parameters:
	// x, y represent the coordinates to render at. w, h represent the width and height of the images.
	// r represents the SDL_Renderer used to render the image in the proper location.
	//Return Values:
	//Precondition: all parameters are defined.
	//Postcondition: Image rendered at x, y with width w and height h.
	void render(int x, int y, int w, int h, SDL_Renderer* r) override;

	//checkReproduce - With random chance, creates a grass in an adjacent open Tile to the calling grass.
	//Pre - The calling grass has been properly associated with a Tile.
	//Post - If an open Tile was randomly selected, a new grass has been created in an adjacent Tile to calling grass.
	void checkReproduce() override;

	//checkDeath - Checks the Grass's current status and adds it to a list of to remove Plants if conditions are met.
	//Pre - TRUE
	//Post - If health is negative, add grass to removal list.
	void checkDeath() override;

	//getPopulationCount - Gets the populationCount for the Grass class.
	//Return - populationCount for the Grass class.
	//Pre - TRUE
	//Post - populationCount for the Grass class has been returned.
	static int getPopulationCount();

	//setTextureImg - Sets static_img for the Grass class to the image for the default grass sprite.
	//Pre - The grass_1.png image is in the project folder.
	//Post - static_img has been set for the Grass class.
	static void setTextureImg();

private:

	//populationCount - The current number of Grass instances in the game.
	static int populationCount;
};

#endif /* GRASS_H_DEFINED */
