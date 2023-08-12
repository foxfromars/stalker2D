#include "../entity.h"
#include "../renderWindow.h"
#include "SDL2/SDL.h"
#include <list>

namespace EngineSystems {

class EntityRenderSystem {
private:
  std::list<EngineHelper::Entity> *entities;
  RenderWindow *rendererPointer;

public:
  std::list<EngineHelper::Entity> getEntities();
  void pushEntity();
  void popEntity();
  void clearEntityList();
  void renderAllEntities();
  EntityRenderSystem(RenderWindow *p_rendererPointer);
  ~EntityRenderSystem();
};

}; // namespace EngineSystems
