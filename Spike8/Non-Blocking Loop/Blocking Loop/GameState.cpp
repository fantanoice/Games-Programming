#include "GameState.h"
#include <iostream>

GameState::GameState(void) {}

GameState::GameState(Game *g) {
	gameController = new GameController(g);
	gameController->SetValidKey(true);
	render = true;
}

GameState::~GameState(void) {}

void GameState::Input(void) {
    gameController->SetInput();
}

bool GameState::Update() {
	if(gameController->GetInput() == "") {
		render = false;
		NotValid();
	}
	else {
		render = true;
		if(gameController->GetInput() == "1") {
			Valid();
			GoToMountainWorld();
		}
		else if(gameController->GetInput() == "2") {
			Valid();
			GoToWaterWorld();
		}
		else if(gameController->GetInput() == "3") {
			Valid();
			GoToBoxWorld();
		}
		else if(gameController->GetInput() == "B" || gameController->GetInput() == "b") {
			Valid();
			GoToMenu();
		}
	}
	return true;
}

void GameState::Render(void) {
	if(!render)
		return;

	if(!gameController->IsValidKey())
		gameController->RenderInvalidKey();	
	else {
		RenderValid();
	}
}

void GameState::RenderValid(void) {
	std::cout << "Zorkish :: Select Adventure\n";
	std::cout << "--------------------------------------------------------\n";
	std::cout << "Choose your adventure:\n";
	std::cout << "1. Mountain World\n";
	std::cout << "2. Water World\n";
	std::cout << "3. Box World\n";
	std::cout << "Or B to go back to the menu.\n";
	std::cout << "_\n";
}

void GameState::NotValid() {
    gameController->NotValid();
}

void GameState::Valid() {
    gameController->Valid();
}

void GameState::GoToWorld(State *s) {
	gameController->GoToWorld(s);
}

void GameState::GoToMenu() {
	gameController->GoToMenu();
}

void GameState::GoToMountainWorld() {
	gameController->GoToMountainWorld();
}

void GameState::GoToWaterWorld() {
	gameController->GoToWaterWorld();
}

void GameState::GoToBoxWorld() {
	gameController->GoToBoxWorld();
}



/*

Historic

GameState::GameState(Game *g) {
	game = g;
	valid = true;
}

void GameState::Render(void) {
	if(valid) {		
		std::cout << "Zorkish :: Select Adventure\n";
		std::cout << "--------------------------------------------------------\n";
		std::cout << "Choose your adventure:\n";
		std::cout << "1. Mountain World\n";
		std::cout << "2. Water World\n";
		std::cout << "3. Box World\n";
		std::cout << "Or B to go back to the menu.\n";
		std::cout << "Select 1-3:> _\n";
	}
	else
		std::cout << "Not a valid key.";
}

void GameState::GoBack(void) {
	game->PopState();
}


void GameState::GoToWorld(State *s) {
	game->PushState(s);
}

void GameState::GoToMenu() {
	game->GoToFirstState();
}


	//std::cin >> input;

*/

/*    if(input =="1") {
		input.clear();
		valid = true;
		GoToWorld(new MountainWorldState(game));
	}
	if(input =="2") {
		input.clear();
		valid = true;
		GoToWorld(new WaterWorldState(game));
	}
	else if(input == "B" || input == "b") {
		input.clear();
		valid = true;
		GoToMenu();
	}
	else {
		input.clear();
		valid = false;
	}*/