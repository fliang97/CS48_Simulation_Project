#ifndef BUTTON_SPEEDDOWN_H_DEFINED
#define BUTTON_SPEEDDOWN_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <cstdlib>
#include "Button.h"

using namespace std;

class Button_Speeddown : public Button {
public:
	Button_Speeddown(int x, int y, int w, int h, SDL_Renderer* r, int & c);

	//Parameters:
	//Return Values:
	//Precondition: Mouse is over button border and is released.
	//Postcondition: Decrease values of map scales.
	void clicked() override;

	//Parameters:
	//Return Values:
	//Precondition:
	//Postcondition: Renders purple rectangle at position and size (temporary)
	//void render() override;

	int & counter;
};

#endif /* BUTTON_SPEEDDOWN_H_DEFINED */
