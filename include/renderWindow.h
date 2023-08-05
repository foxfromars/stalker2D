#include "entity.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class RenderWindow {
private:
  SDL_Window *window;
  SDL_Renderer *renderer;

public:
  void createWindow();
  void closeWindow();
  SDL_Window *getWindow();
  SDL_Renderer *getRenderer();
  void renderEntity(EngineHelper::Entity &p_entity);
  SDL_Texture *loadTexture(const char* texturePath);
};
