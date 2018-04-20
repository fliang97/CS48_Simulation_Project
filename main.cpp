#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <typeinfo>

using namespace std;

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 800;
const int GAME_SPEED = 50;

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Event event;

void Init()
{
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    //SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_RenderClear(renderer);
}

void Close()
{
    SDL_DestroyWindow(window);
    window = NULL;
    SDL_Quit();
}
class Game;
class Entity;
class Grass;
class Cow;
class GameSquare {
public:
  GameSquare(int x, int y, int w, int h, Game* g) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->g = g;
    this->e = NULL;
  }
  void update(vector< vector<GameSquare*> >* nextIterboard);
  void render();
  Entity* e;
  int x;
  int y;
  int w;
  int h;
  Game* g;
};
//Possibly make vectors not pointers because they're already pointers. USE SWAP.
class Game {
public:
  Game(int width, int height);
  void update();
  vector< vector<GameSquare*> >* board;
  vector< vector<GameSquare*> >* bufferboard;
  int width;
  int height;
};

class Entity {
public:
  Entity(GameSquare* parentSquare) {
    this->parentSquare = parentSquare;
  }
//don't move
  virtual void update(vector< vector<GameSquare*> >* nextIterboard) {
    (*nextIterboard)[parentSquare->x][parentSquare->y]->e = new Entity((*nextIterboard)[parentSquare->x][parentSquare->y]);
  }
  virtual void render() {
    //cout << "Entity" << endl;
  }
  GameSquare* parentSquare;
};

class Grass : public Entity {
public:
  Grass(GameSquare* parentSquare): Entity(parentSquare) { }
  void update(vector< vector<GameSquare*> >* nextIterboard) override {
    //Fix rand() to make it change.
    (*nextIterboard)[parentSquare->x][parentSquare->y]->e = new Grass((*nextIterboard)[parentSquare->x][parentSquare->y]);
    if (rand() % 10 == 0) {
      int x = rand() % 3 - 1;
      int y = rand() % 3 - 1;
      vector< vector<GameSquare*> > br = (*parentSquare->g->bufferboard);
      if (parentSquare->x + x >= 0 && parentSquare->x + x < br.size()
    && parentSquare->y + y >= 0 && parentSquare->y + y < br[0].size()) {
        GameSquare* s = br[parentSquare->x + x][parentSquare->y + y];
        //Square must know Entity
        if (!s->e) s->e = new Grass(s);
      }
    }
  }

  void render() override {
    //SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
    SDL_Rect rect = {parentSquare->w*parentSquare->x, parentSquare->h *parentSquare->y, parentSquare->w, parentSquare->h};
    //SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0x00));
    SDL_SetRenderDrawColor( renderer, 0, 255, 0, 255 );
	  SDL_RenderFillRect( renderer, &rect);
	  //SDL_RenderPresent( renderer);
  }
};


class Cow : public Entity {
public:
  Cow(GameSquare* parentSquare): Entity(parentSquare) { }
  void update(vector< vector<GameSquare*> >* nextIterboard) override {
    //Fix rand() to make it change.
    //(*nextIterboard)[parentSquare->x][parentSquare->y]->e = new Grass((*nextIterboard)[parentSquare->x][parentSquare->y]);
    //if (rand() % 10 == 0) {
      int x = rand() % 3 - 1;
      int y = rand() % 3 - 1;
      vector< vector<GameSquare*> > br = (*parentSquare->g->bufferboard);
      if (parentSquare->x + x >= 0 && parentSquare->x + x < br.size()
    && parentSquare->y + y >= 0 && parentSquare->y + y < br[0].size()) {
        GameSquare* s = br[parentSquare->x + x][parentSquare->y + y];
        //Square must know Entity
        cout << parentSquare->x + x << endl;
        if (!s->e) s->e = new Cow(s);
      } else {
        GameSquare* s = br[parentSquare->x][parentSquare->y];
        //Square must know Entity
        if (!s->e) s->e = new Cow(s);
      }
    //}
  }

  void render() override {
    //SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
    SDL_Rect rect = {parentSquare->w*parentSquare->x, parentSquare->h *parentSquare->y, parentSquare->w, parentSquare->h};
    //SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0x00));
    SDL_SetRenderDrawColor( renderer, 100, 50, 0, 255 );
	  SDL_RenderFillRect( renderer, &rect);
	  //SDL_RenderPresent( renderer);
  }
};

Game::Game(int wi, int he): width(wi), height(he) {
  board = new vector< vector<GameSquare*> >(wi, vector<GameSquare*>(he));
  bufferboard = new vector< vector<GameSquare*> >(wi, vector<GameSquare*>(he));
  for (int i = 0; i < wi; ++i) {
    for (int j = 0; j < he; ++j) {
      (*board)[i][j] = new GameSquare(i, j, SCREEN_WIDTH/wi, SCREEN_HEIGHT/he, this);
      (*bufferboard)[i][j] = new GameSquare(i, j, SCREEN_WIDTH/wi, SCREEN_HEIGHT/he, this);
    }
  }
  GameSquare* s = (*board)[5][5];
  //Square must know Entity
  s->e = new Grass(s);
  GameSquare* s2 = (*board)[3][5];
  s2->e = new Cow(s2);
}
void Game::update() {
  //delete entities in bufferboard
  for (int i = 0; i < width; ++i) {
    for (int j = 0; j < height; ++j) {
      (*bufferboard)[i][j]->e = NULL;
    }
  }
  for (int i = 0; i < width; ++i) {
    for (int j = 0; j < height; ++j) {
      (*board)[i][j]->update(bufferboard);
      (*board)[i][j]->render();
    }
  }
  vector< vector<GameSquare*> >* temp = board;
  board = bufferboard;
  bufferboard = temp;
}

void GameSquare::update(vector< vector<GameSquare*> >* nextIterboard) {
  if (e) e->update(nextIterboard);
}
void GameSquare::render() {
  //render self
  if (e) e->render();
}

int main(int argc, char *argv[])
{
    Init();
    bool quit = false;

    Game g(10, 10);
    while (!quit)
    {
        while(SDL_PollEvent(&event) != 0) //To exit loop, call exit(-1)
        {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);
        g.update();
        SDL_RenderPresent(renderer);
        SDL_Delay(10*GAME_SPEED);
    }

    Close();
}



//Mainm
