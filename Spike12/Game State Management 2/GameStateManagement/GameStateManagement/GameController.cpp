#include "GameController.h"
#include "HighScoreState.h"
#include <iostream>
#include "WaterWorldState.h"
#include "MountainWorldState.h"
#include "BoxWorldState.h"

GameController::GameController(void) {}

GameController::GameController(Game *g) {
	game = g;
}

GameController::~GameController(void) {}

void GameController::GoToMenu() {
	game->GoToFirstState();
}

void GameController::GoToHighScore(std::string worldName) {
	game->PushState(new HighScoreState(game, worldName));
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

void GameController::SetInput() {
	std::cin >> input;
}

std::string GameController::GetInput() {
	return input;
}

Game* GameController::GetGame() {
	return game;
}

void GameController::GoToWorld(State *s) {
	game->PushState(s);
}

void GameController::NotValid() {
	SetValid(false);
}

void GameController::Valid() {
   	SetValid(true);
}

void GameController::SetValid(bool b) {
   	input.clear();
    SetValidKey(b);
}

void GameController::GoToMountainWorld() {
	GoToWorld(new MountainWorldState(this));
}

void GameController::GoToWaterWorld() {
	GoToWorld(new WaterWorldState(this));
}

void GameController::GoToBoxWorld() {
	GoToWorld(new BoxWorldState(this));
}