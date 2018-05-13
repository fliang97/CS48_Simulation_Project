#ifndef GRASS_H_DEFINED
#define GRASS_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <cstdlib>

#include "GameSquare.h"
#include "Entity.h"
using namespace std;

class Grass : public Entity {
public:
  Grass(GameSquare* parentSquare): Entity(parentSquare) { }
  void update(vector< vector<GameSquare*> >* nextIterboard) override {
    //Fix rand() to make it change.
    GameSquare* s = (*nextIterboard)[parentSquare->x][parentSquare->y];
    if (!s->e) {
      s->e = this;
      parentSquare->e = NULL;
      parentSquare = s;
    }
    if (rand() % 10 == 0) {
      int x = rand() % 3 - 1;
      int y = rand() % 3 - 1;
      vector< vector<GameSquare*> > br = (*parentSquare->g->bufferboard);
      if (parentSquare->x + x >= 0 && parentSquare->x + x < br.size()
    && parentSquare->y + y >= 0 && parentSquare->y + y < br[0].size()) {
        s = br[parentSquare->x + x][parentSquare->y + y];
        //Square must know Entity
        if (!s->e) {
          s->e = new Grass(s);
        }
      }
    }
  }
  void render(int x, int y, int w, int h) override {
    //SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
    SDL_Rect rect = {x, y, w, h};
    //SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0x00));
    SDL_SetRenderDrawColor( renderer, 100, 50, 0, 255 );
    SDL_RenderFillRect( renderer, &rect);
    //SDL_RenderPresent( renderer);
  }
};
#endif /* GRASS_H_DEFINED */
