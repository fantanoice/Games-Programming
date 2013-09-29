#include "HallOfFameState.h"
#include <iostream>

HallOfFameState::HallOfFameState(void) {}

HallOfFameState::HallOfFameState(Game *g) {
	game = g;
}

HallOfFameState::~HallOfFameState(void) {}

void HallOfFameState::Input(void) {
	std::cin >> input;
}

void HallOfFameState::Update(void) {
	if(input == "B" || input == "b") {
		input.clear();
		GoToMenu();
	}
	else {
		input.clear();
		std::cout << "Not a valid key.";
	}
}

void HallOfFameState::Render(void) {
	std::cout << "Zorkish :: Hall Of Fame\n";
	std::cout << "--------------------------------------------------------\n";
	std::cout << "I dunno, stuff.\n";
	std::cout << "Press B to return to the Main Menu\n";
}

void HallOfFameState::GoBack(void) {
	game->PopState();
}

void HallOfFameState::GoToMenu() {
	game->GoToFirstState();
}