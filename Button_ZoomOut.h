#ifndef BUTTON_ZOOMOUT_H_DEFINED
#define BUTTON_ZOOMOUT_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <cstdlib>
#include "Button.h"

using namespace std;

class Button_ZoomOut : public Button {
public:
	Button_ZoomOut(int x, int y, int w, int h, SDL_Renderer* r, int & scaleX, int & scaleY);

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

	int &scx;
	int &scy;
};

#endif /* BUTTON_ZOOMOUT_H_DEFINED */
