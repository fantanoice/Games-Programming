#include "GameController.h"
#include "HighScore.h"
#include <iostream>


GameController::GameController(void) {}

GameController::GameController(Game *g) {
	game = g;
}

GameController::~GameController(void) {}

void GameController::GoToMenu() {
	game->GoToFirstState();
}

void GameController::GoToHighScore() {
	game->PushState(new HighScore(game));
}

void GameController::SetValidKey(bool b) {
	validKey = b;
}

bool GameController::IsValidKey() {
	return validKey;
}

void GameController::RenderInvalidKey() {
	std::cout << "Not a valid key.";
}

void GameController::SetInput(std::string s) {
	input = s;
}

std::string GameController::GetInput() {
	return input;
}