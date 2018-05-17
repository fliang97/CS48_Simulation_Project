#ifndef BUTTON_ZOOMIN_H_DEFINED
#define BUTTON_ZOOMIN_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <cstdlib>
#include "Button.h"

using namespace std;

class Button_ZoomIn : public Button {
public:
	Button_ZoomIn(int x, int y, int w, int h, SDL_Renderer* r);
	//~Button_Start();
	void clicked() override;
	void render() override;

};

#endif /* BUTTON_ZOOMIN_H_DEFINED */