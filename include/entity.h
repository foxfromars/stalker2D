#pragma once

#include "SDL2/SDL.h"
#include <vector>
namespace EngineHelper {

class Entity {
private:
  float x;
  float y;
  SDL_Rect currentFrame;
  SDL_Texture *tex;
  SDL_Texture *currentTexture;

public:
  Entity(float p_x, float p_y, float p_h, float p_w, SDL_Texture *texture);
  ~Entity();
  std::vector<float> getVectorLocation();
  float getXLocation();
  float getYLocation();
  void setVectorLocation(std::vector<float>);
  void setXLocation(float newXLocation);
  void setYLocation(float newYLocation);
  SDL_Rect *getCurrentFrame();
  SDL_Rect *getCurrentFramePointer();
  SDL_Texture *getCurrentTexture();
  float getHeight();
  float getWidth();
  SDL_Texture * getTexture();
};
} // namespace EngineHelper
