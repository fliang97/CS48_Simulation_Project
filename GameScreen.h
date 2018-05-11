#ifndef GAMESCREEN_H_DEFINED
#define GAMESCREEN_H_DEFINED

#include "Screen.h"
#include "EventHandler.h"
//#include "ScreenManager.h"
class ScreenManager;

class GameScreen : public Screen {
  public:
  GameScreen(EventHandler* eh, ScreenManager* sm, SDL_Renderer* r, int w, int h): Screen(eh, sm, r, w, h) {
  }

  void update() {
  }
  void render() {
    SDL_Rect rect = {0, 0, width, height};
    //SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0x00));
    SDL_SetRenderDrawColor( renderer, 0, 200, 50, 255 );
    SDL_RenderFillRect( renderer, &rect);
  }
};
#endif /* MAINMENUSCREEN_H_DEFINED */
