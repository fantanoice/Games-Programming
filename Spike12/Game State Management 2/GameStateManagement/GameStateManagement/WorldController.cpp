#include "WorldController.h"
#include "HighScore.h"
#include <iostream>


WorldController::WorldController(void) {}

WorldController::WorldController(Game *g) {
	game = g;
}

WorldController::~WorldController(void) {}

void WorldController::GoToMenu() {
	game->GoToFirstState();
}

void WorldController::GoToHighScore() {
	game->PushState(new HighScore(game));
}

void WorldController::SetValidKey(bool b) {
	validKey = b;
}

bool WorldController::IsValidKey() {
	return validKey;
}

void WorldController::RenderInvalidKey() {
	std::cout << "Not a valid key.";
}