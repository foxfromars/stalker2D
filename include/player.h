#pragma once

#include "SDL2/SDL.h"
#include "entity.h"

enum direction {
  up,
  down,
  left,
  right
};

class Player : public EngineHelper::Entity {
private:
  int velocity = 3;

public:
  float health = 200;
  void update();
  void move(direction p_direction);
  void dash(direction p_direction);
  void shoot();
};
