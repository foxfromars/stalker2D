#include "../include/font.h"

void loadFontErrorHandler(const TTF_Font *font, const char *fontPath) {
  if (!font) {
    std::cout << "Error Loading Font " << fontPath << std::endl;
    std::cout << "Error: " << TTF_GetError() << std::endl;
  }
};

Font::Font(SDL_Renderer *p_renderer, int p_fontSize, int p_fontWeight,
           SDL_Color p_color, float p_x, float p_y, fontOption fontOption) {

  fontSize = p_fontSize;
  fontWeight = p_fontWeight;
  color = p_color;
  x = p_x;
  y = p_y;
  renderer = p_renderer;
  text = "Hello world";

  switch (fontOption) {
  case yoster: {
    const char *fontPath = "./assets/yoster.ttf";
    fontFamily = TTF_OpenFont(fontPath, fontSize);
    loadFontErrorHandler(fontFamily, fontPath);
    break;
  }
  case roboto: {
    const char *fontPath = "./assets/roboto.ttf";
    fontFamily = TTF_OpenFont(fontPath, fontSize);
    loadFontErrorHandler(fontFamily, fontPath);
    break;
  }
  default: {
    std::cout << "Invalid font family" << std::endl;
    throw "error";
  }
  };

  SDL_Surface *textSurface = TTF_RenderText_Solid(fontFamily, text, color);
  if (!textSurface) {
    std::cout << "Error Creating Text Surface: " << TTF_GetError() << std::endl;
  }

  fontTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
  if (!fontTexture) {
    std::cout << "Error Creating Text Texture" << SDL_GetError() << std::endl;
  }
};
