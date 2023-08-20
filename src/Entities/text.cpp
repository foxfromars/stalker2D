#include "../../include/Entities/text.h"

void loadFontErrorHandler(const TTF_Font *font, const char *fontPath) {
  if (!font) {
    std::cout << "Error Loading Font " << fontPath << std::endl;
    std::cout << "Error: " << TTF_GetError() << std::endl;
  }
};

void Text::buildText() {
  fontTexture = renderHelper->createTextureFromSurface(
      renderHelper->createTextSurface(fontFamily, text, color));
};

Text::Text(int p_fontSize, int p_fontWeight, SDL_Color p_color, float p_x,
           float p_y, fontOption fontFamilyOption, const char *text)
    : EngineHelper::Entity(p_x, p_y, p_fontSize, p_fontSize) {

  fontSize = p_fontSize;
  fontWeight = p_fontWeight;
  color = p_color;
  setXLocation(p_x);
  setYLocation(p_y);
  text = text;

  switch (fontFamilyOption) {
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

  buildText();
};

SDL_Texture *Text::getTexture() {
  if (fontTexture != NULL) {
    return fontTexture;
  } else {
    throw "Error loading texture";
  }
};

Text::~Text(){

};
