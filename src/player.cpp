#include "../include/player.h"

void Player::move(direction p_direction) {
  SDL_Rect *pFrame = getCurrentFramePointer();

  if (p_direction == up) {
    pFrame->y += velocity;
  } else if (p_direction == down) {
    pFrame->y -= velocity;
  } else if (p_direction == left) {
    pFrame->x -= velocity;
  } else if (p_direction == right) {
    pFrame->x += velocity;
  }
};

