#pragma once
#include "../Helpers/render.h"
#include "../entity.h"
#include "SDL2/SDL.h"
#include <list>

namespace EngineSystems {

class EntityRenderSystem {
private:
  std::list<EngineHelper::Entity> *entities;
  RenderHelper *rendererPointer;

public:
  std::list<EngineHelper::Entity> getEntities();
  void pushEntity();
  void popEntity();
  void clearEntityList();
  void renderAllEntities();
  EntityRenderSystem(RenderHelper *p_rendererPointer);
  ~EntityRenderSystem();
};

}; // namespace EngineSystems
