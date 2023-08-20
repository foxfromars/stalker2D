#include "../include/entity.h"
#include <vector>
using namespace EngineHelper;

Entity::Entity(float p_x, float p_y, float p_h, float p_w,
                             SDL_Texture *texture) {
  currentFrame.x = p_x;
  currentFrame.y = p_y;
  currentFrame.h = p_h;
  currentFrame.w = p_w;
  x = p_x;
  y = p_y;
  tex = texture;
};

Entity::Entity(float p_x, float p_y, float p_h, float p_w) {
   currentFrame.x = p_x;
  currentFrame.y = p_y;
  currentFrame.h = p_h;
  currentFrame.w = p_w;
  x = p_x;
  y = p_y;
        
};

float Entity::getHeight() { return currentFrame.h; }
float Entity::getWidth() { return currentFrame.w; }
float Entity::getYLocation() { return x; };
float Entity::getXLocation() { return y; };
SDL_Rect *Entity::getCurrentFrame() { return &currentFrame; };
SDL_Rect *Entity::getCurrentFramePointer() {
  return &currentFrame;
};
SDL_Texture *Entity::getTexture() { return tex; };
SDL_Texture *Entity::getCurrentTexture() {
  return currentTexture;
};

void Entity::setXLocation(float newXLocation) {
  x = newXLocation;
  currentFrame.x = newXLocation;
};

void Entity::setYLocation(float newYLocation) {
  y = newYLocation;
  currentFrame.y = newYLocation;
};

Entity::~Entity(){};
