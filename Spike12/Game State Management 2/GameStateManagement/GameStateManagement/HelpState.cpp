#include "HelpState.h"
#include <iostream>

HelpState::HelpState(void) {}

HelpState::HelpState(Game *g) {
	game = g;
}

HelpState::~HelpState(void) {}

void HelpState::Input(void) {
	std::cin >> input;
}

void HelpState::Update(void) {
	if(input == "B" || input == "b") {
		input.clear();
		GoToMenu();
	}
	else {
		input.clear();
		std::cout << "Not a valid key.";
	}
}

void HelpState::Render(void) {
	std::cout << "Zorkish :: Help\n";
	std::cout << "--------------------------------------------------------\n";
	std::cout << "Helpy help.\n";
	std::cout << "Press B to return to the Main Menu\n";
}

void HelpState::GoBack(void) {
	game->PopState();
}

void HelpState::GoToMenu() {
	game->GoToFirstState();
}
