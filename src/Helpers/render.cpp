#include "../../include/Helpers/render.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>

void RenderHelper::createWindow() {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cout << "SDL ERROR: " << SDL_GetError() << std::endl;
    return;
  }

  window = SDL_CreateWindow("CUBE", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, 800, 800, 0);
  if (!window) {
    std::cout << "SDL ERROR: " << SDL_GetError() << std::endl;
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  if (!renderer) {
    std::cout << "SDL ERROR: " << SDL_GetError() << std::endl;
  }

  // INIT IMAGE LOADER
  int imgFlags = IMG_INIT_PNG;
  if (!(IMG_Init(imgFlags) & imgFlags)) {
    printf("SDL_image could not initialize! SDL_image Error: %s\n",
           IMG_GetError());
  }

  // INIT TTF FONT LOADER
  if (TTF_Init() < 0) {
    std::cout << "Error initializing font Loader: " << TTF_GetError()
              << std::endl;
  }
};

void RenderHelper::closeWindow() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
};

SDL_Window *RenderHelper::getWindow() { return window; };
SDL_Renderer *RenderHelper::getRenderer() { return renderer; };

SDL_Texture *RenderHelper::loadTexture(const char *texturePath) {
  return IMG_LoadTexture(renderer, texturePath);
};

SDL_Surface *RenderHelper::createTextSurface(TTF_Font *font, const char *text,
                                             SDL_Color color) {
  SDL_Surface *surface = TTF_RenderText_Solid(font, text, color);
  if (!surface) {
    std::cout << "Error Creating Text Surface: " << TTF_GetError() << std::endl;
    throw "error";
  }
  return surface;
};

SDL_Texture *RenderHelper::createTextureFromSurface(SDL_Surface *surface) {
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  if (!texture) {
    std::cout << "Error Creating Text Texture" << SDL_GetError() << std::endl;
    throw "error";
  }
  return texture;
};
