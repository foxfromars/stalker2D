#pragma once

enum gameStateOption { menu, playing, quit };

class GameState {
public:
  gameStateOption currentGameState;
  void changeGameState(gameStateOption newGameState);
  GameState(gameStateOption p_currentGameState);
};
