#include "../../include/Systems/cameraSystem.h"
#include <iterator>

using namespace EngineSystems;

void CameraSystem::changeCameraLocation(Camera *camera, double x, double y) {

  std::vector<float *> cameraCordinates = camera->getLocation();
  *cameraCordinates.at(0) = x;
  *cameraCordinates.at(1) = y;
  std::cout << "newCamera cordinates" << std::endl;
  std::cout << &cameraCordinates.at(0) << std::endl;
  std::cout << &cameraCordinates.at(1) << std::endl;
};

void CameraSystem::changeCameraSize(Camera *camera, double w, double h) {
  std::vector<float *> cameraDimensions = camera->getDimensions();
  *cameraDimensions.at(0) = w;
  *cameraDimensions.at(1) = h;
  std::cout << "newCamera cordinates" << std::endl;
  std::cout << &cameraDimensions.at(0) << std::endl;
  std::cout << &cameraDimensions.at(1) << std::endl;
};

std::list<EngineHelper::Entity>
CameraSystem::getEntitiesInView(Camera camera, EngineEntities::Map map,
                                std::list<EngineHelper::Entity> entities) {
  // TODO math for getting the range of the camera in the Map
  float initX = camera.getX();
  float finalX = initX + camera.getW();
  float initY = camera.getY();
  float finalY = initY + camera.getH();

  std::list<EngineHelper::Entity> filterEntities;
  // TODO filter the entities list

  std::copy_if(
      entities.begin(), entities.end(), std::back_inserter(filterEntities),
      [finalX, initX, initY, finalY](auto entity) {
        if (entity.getXLocation() >= initX && entity.getXLocation() <= finalX &&
            entity.getYLocation() >= initY && entity.getYLocation() <= finalY) {
          return true;
        } else {
          return false;
        }
      });
  return filterEntities;
};

void CameraSystem::moveCamera(Camera *camera, direction cameraDirection) {
  switch (cameraDirection) {
  case up: {
    camera->setY(camera->getY() + velocity);
    break;
  }
  case down: {
    camera->setY(camera->getY() - velocity);
    break;
  }
  case left: {
    camera->setX(camera->getX() - velocity);
    break;
  }
  case right: {
    camera->setX(camera->getX() + velocity);
    break;
  }
  }
};
