#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "../font.h"

class RenderHelper {
private:
  SDL_Window *window;
  SDL_Renderer *renderer;

public:
  void createWindow();
  void clearSurface();
  void updateSurface();
  void closeWindow();
  SDL_Window *getWindow();
  SDL_Renderer *getRenderer();
  SDL_Texture *loadTexture(const char *texturePath);
};
