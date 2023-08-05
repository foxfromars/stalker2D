#include "../include/entity.h"
#include <vector>

EngineHelper::Entity::Entity(float p_x, float p_y, float p_h, float p_w,
                             std::vector<SDL_Texture *> texture) {
  currentFrame.x = p_x;
  currentFrame.y = p_y;
  currentFrame.h = p_h;
  currentFrame.w = p_w;
  tex = texture;
};

float EngineHelper::Entity::getHeight() { return currentFrame.h; }
float EngineHelper::Entity::getWidth() { return currentFrame.w; }
float EngineHelper::Entity::getYLocation() { return x; };
float EngineHelper::Entity::getXLocation() { return y; };
SDL_Rect EngineHelper::Entity::getCurrentFrame() { return currentFrame; };
SDL_Rect *EngineHelper::Entity::getCurrentFramePointer() { return &currentFrame; };
std::vector<SDL_Texture *> EngineHelper::Entity::getTexture() { return tex; };

EngineHelper::Entity::~Entity(){};
