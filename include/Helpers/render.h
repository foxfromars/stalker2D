#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

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
  SDL_Surface *createTextSurface(TTF_Font *font, const char *text,
                                 SDL_Color color);
  SDL_Texture *createTextureFromSurface(SDL_Surface *surface);
};
