#include "../include/gameState.h"

void GameState::changeGameState(gameStateOption newGameState) {
  currentGameState = newGameState;
};

GameState::GameState(gameStateOption p_currentGameState) {
  currentGameState = p_currentGameState;
};
