#include "SDL2/SDL.h"
#include "entity.h"

enum direction {
  up = 0,
  down = 1,
  left = 2,
  right = 3
};

class Player : public EngineHelper::Entity {
private:
  int velocity = 3;

public:
  int health = 200;
  void update();
  void move(direction p_direction);
  void shoot();
  void dash();
};
