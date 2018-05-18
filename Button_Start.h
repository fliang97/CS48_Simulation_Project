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
	//~Button_Start();
	void clicked() override;
  void pressed() override;
  void released() override;
	void render() override;
  SDL_Texture *unclicked_img;
  SDL_Texture *clicked_img;
  SDL_Texture *current_img;
	int& currentScreen;
	Map& map;
};
#endif /* STARTBUTTON_H_DEFINED */
