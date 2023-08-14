#include "../../include/Systems/inputSystem.h"

std::vector<int> Input::getMouseLocation() {
  int x, y;
  SDL_GetMouseState(&x, &y);
  return {x, y};
};

void Input::processInput() {
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
    }
  }
}
