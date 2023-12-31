#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <vector>
#include <iterator>
#include <list>

#include "../include/entity.h"
#include "../include/Helpers/render.h"
#include "../include/Entities/camera.h"
#include "../include/Entities/map.h"
#include "../include/Systems/cameraSystem.h"
#include "../include/Systems/entityRenderSystem.h"
#include "../include/Systems/fontSystem.h"
#include "../include/Entities/text.h"

class Application {
public:
  void loop();
  void renderTime(int time, SDL_Texture *text_texture);
  Application();
  ~Application();
};
