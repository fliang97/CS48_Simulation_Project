#ifndef COMPONENT_H_DEFINED
#define COMPONENT_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Component {
public:
	Component(int x, int y, int w, int h, SDL_Renderer* r);
	//~Component();

	virtual bool isOver(int mousex, int mousey);

	//Parameters:
	//Return Values:
	//Precondition: Mouse is over Component border and is released.
	//Postcondition: Abstract functionality
	virtual void clicked();

	//Parameters:
	//Return Values:
	//Precondition: Mouse is over Component border  and is just pressed.
	//Postcondition: Abstract functionality
	virtual void pressed();

	//Parameters:
	//Return Values:
	//Precondition: Mouse is just released. Note: doesn't have to be over Component border
	//Postcondition: Abstract functionality
	virtual void released();

	//Parameters:
  //Return Values:
  //Precondition:
  //Postcondition: Abstract functionality
	virtual void render();

	int xpos;
	int ypos;
	int width;
	int height;
	SDL_Renderer* renderer;
};
#endif /* COMPONENT_H_DEFINED */
