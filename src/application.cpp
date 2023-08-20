#include "../include/application.h"
#include <SDL2/SDL_render.h>
#include <list>

RenderHelper render;

Application::Application() { render.createWindow(); };

Application::~Application() { render.closeWindow(); };

void Application::loop() {
  // creating the map
  EngineEntities::Map mapEntity = EngineEntities::Map(800, 800);

  // create camera
  Camera cameraEntity = Camera(0, 0, 100, 100);
  EngineSystems::EntityRenderSystem entityRenderSystem =
      EngineSystems::EntityRenderSystem(render.getRenderer());
  EngineSystems::FontSystem fontSystem = EngineSystems::FontSystem(&render);
  EngineSystems::CameraSystem cameraSystem;
  bool windowOpen = true;
  int time;
  std::list<EngineHelper::Entity> entities;
  SDL_Texture *grassTexture = render.loadTexture("./assets/grass.png");
  entities.push_back(EngineHelper::Entity(300, 400, 30, 30, grassTexture));
  entities.push_back(EngineHelper::Entity(50, 400, 30, 30, grassTexture));
  entities.push_back(EngineHelper::Entity(400, 60, 400, 400, grassTexture));
  entities.push_back(EngineHelper::Entity(50, 70, 30, 30, grassTexture));
  entities.push_back(EngineHelper::Entity(60, 80, 30, 30, grassTexture));

  std::cout << "Number of entities" << entities.size() << std::endl;

  /* Text testeText = Text(10, 10, {254, 0, 0}, 10, 10, yoster, "hello world");
   */

  while (windowOpen) {
    Uint64 start = SDL_GetPerformanceCounter();
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        windowOpen = false;
      } else if (event.key.keysym.sym == SDLK_w) {
        cameraSystem.moveCamera(&cameraEntity, up);
      } else if (event.key.keysym.sym == SDLK_s) {
        cameraSystem.moveCamera(&cameraEntity, down);
      } else if (event.key.keysym.sym == SDLK_a) {
        cameraSystem.moveCamera(&cameraEntity, left);
      } else if (event.key.keysym.sym == SDLK_d) {
        cameraSystem.moveCamera(&cameraEntity, right);
      }
    }

    std::cout << cameraEntity.getX() << std::endl;
    std::cout << cameraEntity.getY() << std::endl;

    SDL_RenderClear(render.getRenderer());
    /* SDL_RenderCopy(render.getRenderer(), texture, &rect, &rect); */

    // TODO create entities in the mapEntities
    // TODO get Entities in the radius of the camera
    std::list<EngineHelper::Entity> entitiesToRender =
        cameraSystem.getEntitiesInView(cameraEntity, mapEntity, entities);
    std::cout << "Entities to render: " << entitiesToRender.size() << std::endl;
    entityRenderSystem.renderAllEntitiesInTheCamera(cameraEntity,
                                                    entitiesToRender);

    /* fontSystem.renderText(&testeText); */

    // TODO Render this entities in the screen
    // Draw black background
    SDL_SetRenderDrawColor(render.getRenderer(), 0, 0, 0, 255);
    SDL_RenderPresent(render.getRenderer());

    // limit fps to 60
    Uint64 end = SDL_GetPerformanceCounter();
    float elapsedMS =
        ((end - start) / (float)SDL_GetPerformanceFrequency()) * 1000.0f;
    SDL_Delay(floor(16.666f - elapsedMS));
    time = floor(SDL_GetTicks() / 1000.0f);
  }
};
