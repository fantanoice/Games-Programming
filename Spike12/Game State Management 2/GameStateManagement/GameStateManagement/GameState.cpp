#include "GameState.h"
#include <iostream>
#include "WaterWorldState.h"

GameState::GameState(void) {
	valid = true;
}

GameState::GameState(Game *g) {
	game = g;
	valid = true;
}

GameState::~GameState(void) {}

void GameState::Input(void) {
	std::cin >> input;
}

void GameState::Update(void) {
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
	}
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

void GameState::GoToWorld(State *s) {
	game->PushState(s);
}

void GameState::GoBack(void) {
	game->PopState();
}

void GameState::GoToMenu() {
	game->GoToFirstState();
}
