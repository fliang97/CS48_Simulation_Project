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
	virtual void clicked() override;
	virtual void render()  override;

};
#endif /* BUTTON_H_DEFINED */
