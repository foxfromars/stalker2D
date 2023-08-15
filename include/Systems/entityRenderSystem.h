#pragma once
#include "../Entities/camera.h"
#include "../Helpers/render.h"
#include "../entity.h"
#include "SDL2/SDL.h"
#include <list>

namespace EngineSystems {

class EntityRenderSystem {
private:
  std::list<EngineHelper::Entity> *entities = NULL;
  SDL_Renderer *rendererPointer;

public:
  std::list<EngineHelper::Entity> getEntities();
  void pushEntity();
  void popEntity();
  void clearEntityList();
  void renderEntity(EngineHelper::Entity entity);
  void renderAllEntities();
  void renderAllEntitiesInTheCamera(Camera camera,
                                    std::list<EngineHelper::Entity> entities);
  EntityRenderSystem(SDL_Renderer *p_rendererPointer);
  ~EntityRenderSystem();
};

}; // namespace EngineSystems
