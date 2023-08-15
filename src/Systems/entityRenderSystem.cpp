#include "../../include/Systems/entityRenderSystem.h"
#include <SDL2/SDL_render.h>
using namespace EngineSystems;

EntityRenderSystem::EntityRenderSystem(SDL_Renderer *p_rendererPointer) {
  rendererPointer = p_rendererPointer;
};

void EntityRenderSystem::renderEntity(EngineHelper::Entity entity) {
  SDL_RenderCopy(rendererPointer, entity.getTexture(), entity.getCurrentFrame(),
                 entity.getCurrentFrame());
};

void EntityRenderSystem::renderAllEntities() {
  for (EngineHelper::Entity entity : *entities) {
    renderEntity(entity);
  };
};

void EntityRenderSystem::renderAllEntitiesInTheCamera(
    Camera camera, std::list<EngineHelper::Entity> entities) {
  float initX = camera.getX();
  float finalX = initX + camera.getW();

  float initY = camera.getY();
  float finalY = initY + camera.getH();

  for (auto &&entity : entities) {
    std::cout << "Entity Rendering" << std::endl;
    entity.setYLocation(entity.getYLocation() - initY); 
    entity.setXLocation(entity.getXLocation() - initX);
    renderEntity(entity);
  };
};

EntityRenderSystem::~EntityRenderSystem() {
  // cleaning the entities list in the heap memory
  // TODO clear textures loaded in the entities
  if (entities != NULL) {
    // clear entities
    delete entities;
  }
};
