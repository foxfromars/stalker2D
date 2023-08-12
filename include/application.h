#pragma once

#include "input.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <vector>

class Application {
public:
  Input inputHandler;
  void loop();
  void renderTime(int time, SDL_Texture *text_texture);
  Application();
  ~Application();
};
