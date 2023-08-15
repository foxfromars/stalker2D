#include "../../include/Entities/camera.h"

std::vector<float *> Camera::getDimensions() { return {&w, &h}; };

std::vector<float *> Camera::getLocation() { return {&x, &y}; };

float Camera::getX() { return x; };

float Camera::getY() { return y; };

float Camera::getW() { return w; };

float Camera::getH() { return h; };

void Camera::setX(float p_x) { x = p_x; };

void Camera::setY(float p_y) { y = p_y; };

void Camera::setW(float p_w) { w = p_w; };

void Camera::setH(float p_h) { h = p_h; };

Camera::Camera(float p_x, float p_y, float p_w, float p_h) {
  x = p_x;
  y = p_y;
  w = p_w;
  h = p_h;
};
