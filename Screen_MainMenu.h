#ifndef SCREEN_MAINMENU_H_DEFINED
#define SCREEN_MAINMENU_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Button_Start.h"
#include "Screen.h"
#include "EventHandler.h"
using namespace std;
//#include "ScreenManager.h"
class ScreenManager;


class Screen_MainMenu : public Screen {
  public:
  Screen_MainMenu(EventHandler* eventHandler, SDL_Renderer* r, int w, int h, int& cs, Map& map): Screen(eventHandler, r, w, h) {
    button_start = new Button_Start(width/3, height/3, width/3, height/3, r, cs, map);
    components.push_back(button_start);
  }

  //~Screen_MainMenu() {
  //  delete button_start;
  //}

  void update() override{
  }
  void render() override {
    SDL_Rect rect = {0, 0, width, height};
    //SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0x00));
    SDL_SetRenderDrawColor( renderer, 100, 0, 100, 255 );
    SDL_RenderFillRect( renderer, &rect);
    //cout <<  rect.w << endl;
    button_start->render();
  }
private:
  Button_Start* button_start;
};


#endif /* SCREEN_MAINMENU_H_DEFINED */
