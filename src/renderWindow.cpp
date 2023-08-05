#include "../include/renderWindow.h"
#include <SDL2/SDL_render.h>

void RenderWindow::createWindow() {
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

  int imgFlags = IMG_INIT_PNG;
  if (!(IMG_Init(imgFlags) & imgFlags)) {
    printf("SDL_image could not initialize! SDL_image Error: %s\n",
           IMG_GetError());
  }
};

void RenderWindow::closeWindow() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
}

void RenderWindow::renderEntity(EngineHelper::Entity &p_entity) {
  SDL_Rect src;
  src.h = p_entity.getCurrentFrame().h;
  src.w = p_entity.getCurrentFrame().w;
  src.x = p_entity.getCurrentFrame().x;
  src.y = p_entity.getCurrentFrame().y;

  SDL_RenderCopy(getRenderer(), p_entity.getTexture().at(0), &src, &src);
};

SDL_Texture *RenderWindow::loadTexture(const char *texturePath) {
  SDL_Texture *tex = NULL;
  tex = IMG_LoadTexture(renderer, texturePath);

  if (tex == NULL) {
    std::cout << "Error Loading texture in:" << texturePath << std::endl;
  }

  return tex;
};

SDL_Window *RenderWindow::getWindow() { return window; };
SDL_Renderer *RenderWindow::getRenderer() { return renderer; };
