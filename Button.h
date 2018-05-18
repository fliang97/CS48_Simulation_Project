#ifndef BUTTON_H_DEFINED
#define BUTTON_H_DEFINED

#include "Component.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Button : public Component{
public:
	Button(int x, int y, int w, int h, SDL_Renderer* r);
	virtual void clicked() override; //mouse released on button

	//Parameters:
	//Return Values:
	//Precondition: Mouse is over button border and is just pressed.
	//Postcondition: Sets current_img to clicked_img
	void pressed() override;

	//Parameters:
	//Return Values:
	//Precondition: Mouse is just released. Note: doesn't have to be over button
	//Postcondition: Sets current_img to unlicked_img
	void released() override;

	virtual void render()  override;

	SDL_Texture *unclicked_img;
	SDL_Texture *clicked_img;
	SDL_Texture *current_img;

};
#endif /* BUTTON_H_DEFINED */
