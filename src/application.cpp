#include <SDL2/SDL_render.h>
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>

#include "../include/application.h"
#include "../include/entity.h"
#include "../include/renderWindow.h"

RenderWindow render;

Application::Application() { render.createWindow(); };

Application::~Application() { render.closeWindow(); };

void Application::loop() {
  bool windowOpen = true;
  int time;

  SDL_Rect rect;
  SDL_Texture *texture = render.loadTexture("./assets/grass.png");
  rect.x = 250;
  rect.y = 150;
  rect.w = 200;
  rect.h = 200;

  while (windowOpen) {
    Uint64 start = SDL_GetPerformanceCounter();
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        windowOpen = false;
      }
    }

    SDL_RenderClear(render.getRenderer());

    SDL_RenderCopy(render.getRenderer(), texture, &rect, &rect);

    // Draw black background
    SDL_SetRenderDrawColor(render.getRenderer(), 0, 0, 0, 255);
    SDL_RenderPresent(render.getRenderer());


    // limit fps to 60
    Uint64 end = SDL_GetPerformanceCounter();
    float elapsedMS =
        ((end - start) / (float)SDL_GetPerformanceFrequency()) * 1000.0f;
    SDL_Delay(floor(16.666f - elapsedMS));
    time = floor(SDL_GetTicks() / 1000.0f);
  }
};
