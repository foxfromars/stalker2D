#include "../../include/Systems/entityRenderSystem.h"
using namespace EngineSystems;

EntityRenderSystem::EntityRenderSystem(RenderWindow *p_rendererPointer) {
  rendererPointer = p_rendererPointer;
};

void EntityRenderSystem::renderAllEntities() {
  for (EngineHelper::Entity entity : *entities) {
  };
};

EntityRenderSystem::~EntityRenderSystem() {
  // cleaning the entities list in the heap memory
  // TODO clear textures loaded in the entities
  delete entities;
};
