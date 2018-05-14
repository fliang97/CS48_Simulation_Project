#ifndef MAINMENUSCREEN_H_DEFINED
#define MAINMENUSCREEN_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <vector>
#include <cstdlib>

#include "StartButton.h"
#include "Screen.h"
#include "EventHandler.h"
using namespace std;
//#include "ScreenManager.h"
class ScreenManager;


class MainMenuScreen : public Screen {
  public:
  MainMenuScreen(EventHandler* eventHandler, SDL_Renderer* r, int w, int h, int& cs, GameState& gameState): Screen(eventHandler, r, w, h) {
    startButton = new StartButton(width/3, height/3, width/3, height/3, r, cs, gameState);
    components.push_back(startButton);
  }

  //~MainMenuScreen() {
  //  delete startButton;
  //}

  void update() override{
  }
  void render() override {
    SDL_Rect rect = {0, 0, width, height};
    //SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0x00));
    SDL_SetRenderDrawColor( renderer, 100, 0, 100, 255 );
    SDL_RenderFillRect( renderer, &rect);
    //cout <<  rect.w << endl;
    startButton->render();
  }
private:
  StartButton* startButton;
};


#endif /* MAINMENUSCREEN_H_DEFINED */
