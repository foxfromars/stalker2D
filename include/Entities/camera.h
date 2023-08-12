#pragma once
#include "SDL2/SDL.h"
#include <vector>

class Camera {
private:
  float x, y;
  float w, h;

public:
  std::vector<float> getLocation();
  std::vector<float> getDimensions();
  void changeLocation(float p_x, float p_y);
  Camera(float p_x, float p_y, float p_w, float p_h);
};
