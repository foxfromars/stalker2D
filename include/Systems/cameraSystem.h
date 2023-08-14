#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

#include "../Entities/camera.h"
#include "../Entities/map.h"
#include "../Utils/errorUtils.h"
#include "../entity.h"

enum direction {
  up,
  down,
  left,
  right,
};

namespace EngineSystems {

class CameraSystem {
private:
  double velocity = 5;

public:
  void changeCameraLocation(Camera *camera, double x, double y);
  void changeCameraSize(Camera *camera, double w, double h);
  void moveCamera(Camera *camera, direction cameraDirection);
  std::list<EngineHelper::Entity>
  getEntitiesInView(Camera camera, EngineEntities::Map map,
                    std::list<EngineHelper::Entity> entities);
};

} // namespace EngineSystems
