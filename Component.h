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
	virtual void clicked();
	virtual void pressed();
	virtual void released();
	virtual void render();

	int xpos;
	int ypos;
	int width;
	int height;
	SDL_Renderer* renderer;
};
#endif /* COMPONENT_H_DEFINED */
