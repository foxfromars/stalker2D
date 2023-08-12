#include "../../include/Entities/camera.h"

std::vector<float> Camera::getDimensions() { return {w, h}; };

std::vector<float> Camera::getLocation() { return {x, y}; };

void Camera::changeLocation(float p_x, float p_y) {
  x = p_x;
  y = p_y;
};

Camera::Camera(float p_x, float p_y, float p_w, float p_h) {
  x = p_x;
  y = p_y;
  w = p_w;
  h = p_h;
};
