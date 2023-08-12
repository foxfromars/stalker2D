#pragma once

#include <vector>
namespace EngineEntities {

class Map {
private:
  double w, h;

public:
  std::vector<double> getDimensions();
  Map(double p_w, double p_h);
};

}; // namespace EngineEntities
