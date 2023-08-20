#pragma once

#include "../Helpers/render.h"
#include "../entity.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include "../Utils/errorUtils.h"

enum fontOption { yoster, roboto };

class Text : public EngineHelper::Entity {
private:
  RenderHelper *renderHelper;
  int fontSize;
  int fontWeight;
  TTF_Font *fontFamily;
  SDL_Color color;
  const char *text;
  SDL_Texture *fontTexture = NULL;

public:
  void buildText();

  void changeText(const char *newText);
  void changeColor(SDL_Color newColor);
  void changeFontSize(int newFontSize);
  SDL_Texture *getTexture();

  int getSize();
  int getWeight();
  SDL_Color getColor();
  const char *getText();

  Text(int p_fontSize, int p_fontWeight, SDL_Color p_color, float p_x,
       float p_y, fontOption fontFamilyOption, const char *text);

  ~Text();
};
