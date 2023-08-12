#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

enum fontOption { yoster, roboto };

class Font {
private:
  SDL_Renderer *renderer;

public:
  int fontSize;
  int fontWeight;
  TTF_Font *fontFamily;
  SDL_Color color;
  const char *text;
  float x;
  float y;
  SDL_Texture *fontTexture;

  Font(SDL_Renderer *renderer,int p_fontSize, int p_fontWeight, SDL_Color p_color, float p_x,
       float p_y, fontOption fontFamily);
};
