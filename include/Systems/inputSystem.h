#pragma once

#include "SDL2/SDL.h"
#include <vector>

class Input {
public:
  std::vector<int> getMouseLocation();
  void processInput();
};

