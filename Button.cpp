#include "Component.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <cstdlib>
#include "Button.h"

using namespace std;

Button::Button(int x, int y, int w, int h, SDL_Renderer* r) : Component(x, y, w, h, r) {
}

void Button::clicked() {
}

void Button::pressed() {
}

void Button::released() {
}

void Button::render() {

}
