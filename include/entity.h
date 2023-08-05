#pragma once

#include "SDL2/SDL.h"
#include "vector"
#include <vector>
namespace EngineHelper {

class Entity {
private:
  float x;
  float y;
  SDL_Rect currentFrame;
  std::vector<SDL_Texture *> tex;

public:
  Entity(float p_x, float p_y, float p_h, float p_w,
         std::vector<SDL_Texture *> texture);
  ~Entity();
  std::vector<float> getVectorLocation();
  float getXLocation();
  float getYLocation();
  void setVectorLocation(std::vector<float>);
  void setXLocation(float newXLocation);
  void setYLocation(float newYLocation);
  SDL_Rect getCurrentFrame();
  SDL_Rect *getCurrentFramePointer();
  float getHeight();
  float getWidth();
  std::vector<SDL_Texture *> getTexture();
};
} // namespace EngineHelper
