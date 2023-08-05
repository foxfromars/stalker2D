#include "SDL2/SDL.h"
#include "renderWindow.h"
#include <vector>

class Input {
public:
  std::vector<int> getMouseLocation();
  void processInput(RenderWindow render);
};

