#include <SDL.h>
#include <iostream>
#include <vector>

using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
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
    SDL_RenderClear(renderer);
}

void Close()
{
    SDL_DestroyWindow(window);
    window = NULL;
    SDL_Quit();
}


class GameSquare {
public:
  GameSquare(int x, int y, int w, int h, Game& g) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->g = g;
  }
  void update(vector< vector<GameSquare> >& nextIterboard) {
    e.update(nextIterboard);
  }
  void render() {
    //render self
    e.render();
  }
  Entity& e;
  int x;
  int y;
  int w;
  int h;
  Game& g;

};
class Entity {
public:
  Entity(GameSquare& parentSquare) {
    this->parentSquare = parentSquare;
  }
//don't move
  void update(vector< vector<GameSquare> >& nextIterboard) {
    nextIterboard[parentSquare.x][parentSquare.y].e = new Entity(nextIterboard[parentSquare.x][parentSquare.y]);
  }
  void render() {
  }
  GameSquare& parentSquare;
};

class Grass : Entity {
public:
  Grass(GameSquare& parentSquare) {
    this->parentSquare = parentSquare;
  }

  void update(vector< vector<GameSquare> >& nextIterboard) {
    nextIterboard[parentSquare.x][parentSquare.y].e = new Grass(nextIterboard[parentSquare.x][parentSquare.y]);
    if (rand() % 1000 == 0) {
      int x = rand() % 3 - 1;
      int y = rand() % 3 - 1;
      if (!(x == 0 && y == 0)) {
        GameSquare& s = parentSquare.g.board[parentSquare.x+x][parentSquare.y+y];
        //Square must know Entity
        s.e = new Grass(s);
      }
    }
  }

  void render() {
    SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
    SDL_Rect rect(parentSquare.x, parentSquare.y, parentSquare.w, parentSquare.h);
    SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0x00));
  }
};

class Game {
public:
  Game(int length, int width) {
    for (int i : length) {
      vector<GameSquare> v;
      for (int j : width) {
        v.push_back(new GameSquare(i, j, SCREEN_WIDTH/width, SCREEN_HEIGHT/height, this));
      }
      board.push_back(v);
      delete v;
    }
  }

  void update() {
    for (int i : length) {
      for (int j : width) {
        board[i][j].update(*bufferboard);
        board[i][j].render();
      }
    }
    displayboard = board;
    board
  }
  vector< vector<GameSquare> > board;
  vector< vector<GameSquare> > board2;
  vector< vector<GameSquare> >* displayboard;
  vector< vector<GameSquare> >* bufferboard;

};

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
        SDL_Delay(GAME_SPEED);
    }

    Close();
}



//Mainm
