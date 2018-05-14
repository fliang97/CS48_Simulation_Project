#ifndef COMPONENT_H_DEFINED
#define COMPONENT_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//#include <SDL.h>

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Component {
public:
  Component(int x, int y, int w, int h, SDL_Renderer* r): xpos(x), ypos(y), width(w), height(h), renderer(r) {
  }
  //~Component() {
  //  delete renderer;
  //}
  virtual bool isOver(int mousex, int mousey) {
    bool over = (mousex >= xpos && mousex < (xpos + width) && mousey >= ypos && mousey < (ypos + height));
    cout << over << endl;
    return over;
  }
  virtual void clicked() {
    //cout << "Clicked3" << endl;
  }
  virtual void render() {

  }

  int xpos;
  int ypos;
  int width;
  int height;
  SDL_Renderer* renderer;
};
#endif /* COMPONENT_H_DEFINED */
