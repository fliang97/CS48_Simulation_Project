#ifndef SCREEN_H_DEFINED
#define SCREEN_H_DEFINED

#include "EventHandler.h"
//#include "ScreenManager.h"
#include "Component.h"
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
class ScreenManager;
class EventHandler;

class Screen {
  public:
  Screen(EventHandler* eh, ScreenManager* sm, SDL_Renderer* r, int w, int h): width(w), height(h), renderer(r) {
    this->eh = eh;
    this->sm = sm;
  }
  void mousePressed() {
    for (Component* c : components) {
      if (c->isOver(eh->xMouse, eh->yMouse)) {
        c->clicked();
      }
    }
  }
  void update() {
  }
  void render() {
  }
  SDL_Renderer* renderer;
  vector< Component* > components;
  EventHandler* eh;
  ScreenManager* sm;
  int width;
  int height;
};
#endif /* SCREEN_H_DEFINED */
