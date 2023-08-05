#include <SDL2/SDL.h>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <vector>
#include <SDL2/SDL_image.h>
#include "../include/application.h"

class Point {
public:
  double x = 0;
  double y = 0;
  double z = 0;

  Point() {}
};


int main(int argc, char **argv) {
  Application app;
  std::cout << "Program initialize" << std::endl;
  app.loop();
  return 0;
}
