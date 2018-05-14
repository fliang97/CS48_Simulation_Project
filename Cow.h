#ifndef COW_H_DEFINED
#define COW_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <cstdlib>

#include "GameState.h"
#include "GameSquare.h"
#include "Entity.h"
using namespace std;

class Cow : public Entity {
public:
  Cow(GameSquare* parentSquare): Entity(parentSquare) { }
  void update(vector< vector<GameSquare*> >* nextIterboard) override {
    cout << "CowUpdate" << endl;
      GameSquare* s = (*nextIterboard)[parentSquare->x][parentSquare->y];
      int x = rand() % 3 - 1;
      int y = rand() % 3 - 1;
      if (parentSquare->x + x >= 0 && parentSquare->x + x < nextIterboard->size()
    && parentSquare->y + y >= 0 && parentSquare->y + y < (*nextIterboard)[0].size()) {
        s = (*nextIterboard)[parentSquare->x + x][parentSquare->y + y];
        //Square must know Entity
        s->e = this;
        parentSquare->e = NULL;
        parentSquare = s;
      } else {
         GameSquare* s = (*nextIterboard)[parentSquare->x][parentSquare->y];
         //Square must know Entity
         //if (!s->e) //gets overriden if something moves into it. This now overrides anything on it.
         s->e = this;
         parentSquare->e = NULL;
         parentSquare = s;

      }
  }
  void render(int x, int y, int w, int h, SDL_Renderer* r) override {
    //cout << "GrassRender" << endl;
    //SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
    SDL_Rect rect = {x, y, w, h};
    //SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0x00));
    SDL_SetRenderDrawColor(r, 100, 50, 0, 255 );
    SDL_RenderFillRect(r, &rect);
    //SDL_RenderPresent( renderer);
  }

};
#endif /* COW_H_DEFINED */
