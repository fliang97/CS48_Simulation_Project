#ifndef STARTBUTTON_H_DEFINED
#define STARTBUTTON_H_DEFINED


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Button.h"
#include "Entity.h"
#include "Grass.h"
#include "Cow.h"
#include "Map.h"

using namespace std;
class ScreenManager;

class Button_Start : public Button {
public:
	Button_Start(int x, int y, int w, int h, SDL_Renderer* r, int& currentScreen, Map& map);

  //Parameters:
  //Return Values:
  //Precondition: Mouse is over button border and is released.
  //Postcondition: Calls constructor of Map. Adds starting elements to map.
	void clicked() override;

  //Parameters:
  //Return Values:
  //Precondition:
  //Postcondition: Renders current_img at position and size
	void render() override;

	int& currentScreen;
	Map& map;
};
#endif /* STARTBUTTON_H_DEFINED */
