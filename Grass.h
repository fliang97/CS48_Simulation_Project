#ifndef GRASS_H_DEFINED
#define GRASS_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <vector>
#include <cstdlib>

#include "GameState.h"
#include "GameSquare.h"
#include "Entity.h"
using namespace std;

class Grass : public Entity {
public:
  Grass(GameSquare* parentSquare): Entity(parentSquare) { }
  void update(vector< vector<GameSquare*> >* nextIterboard) override {
    cout << "GrassUpdate" << endl;
    //Fix rand() to make it change.
    GameSquare* s = (*nextIterboard)[parentSquare->x][parentSquare->y];
    if (!s->e) {
      s->e = this;
      parentSquare->e = NULL;
      parentSquare = s;
    }
    if (rand() % 10 == 0) {
      //cout << "Time to spread" << endl;
      int x = rand() % 3 - 1;
      int y = rand() % 3 - 1;
      if (parentSquare->x + x >= 0 && parentSquare->x + x < static_cast<int>(nextIterboard->size())
    && parentSquare->y + y >= 0 && parentSquare->y + y < static_cast<int>((*nextIterboard)[0].size())) {
        //cout << "Time to spread20" << endl;
        s = (*nextIterboard)[parentSquare->x + x][parentSquare->y + y];
        //cout << "Time to spread2" << endl;
        //Square must know Entity
        if (!s->e) {
          s->e = new Grass(s);
          //cout << "Time to spread3" << endl;
        }
      }
    }
  }
  void render(int x, int y, int w, int h, SDL_Renderer* r) override {
    //cout << "GrassRender" << endl;
    //SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
    SDL_Rect rect = {x, y, w, h};
    //SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0x00));
    SDL_SetRenderDrawColor(r, 0, 255, 0, 255 );
    SDL_RenderFillRect(r, &rect);
    //SDL_RenderPresent( renderer);
  }
};
#endif /* GRASS_H_DEFINED */
