#include "AboutState.h"
#include <iostream>

AboutState::AboutState(void) {}

AboutState::AboutState(Game *g) {
	game = g;
}

AboutState::~AboutState(void) {}

void AboutState::Input(void) {
	std::cin >> input;
}

void AboutState::Update(void) {
	if(input == "B" || input == "b") {
		input.clear();
		GoToMenu();
	}
	else {
		input.clear();
		std::cout << "Not a valid key.";
	}
}

void AboutState::Render(void) {
	std::cout << "Zorkish :: About\n";
	std::cout << "--------------------------------------------------------\n";
	std::cout << "Written by: Rachel McQueenie\n";
	std::cout << "Press B to return to the Main Menu\n";
}

void AboutState::GoBack(void) {
	game->PopState();
}

void AboutState::GoToMenu() {
	game->GoToFirstState();
}
