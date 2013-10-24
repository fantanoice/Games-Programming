#include "AboutState.h"
#include <iostream>

AboutState::AboutState(void) {}

AboutState::AboutState(Game *g) {
	game = g;
	invalid = false;
	render = true;
}

AboutState::~AboutState(void) {}

void AboutState::Input(void) {
	std::cin >> input;
}

bool AboutState::Update() {
	if(input == "") {
		input.clear();
		render = false;
	}
	else {
		render = true;
		if(input == "B" || input == "b") {
			input.clear();
			GoToMenu();
		}
		else if (input != "") {
			input.clear();
			invalid = true;
		}
	}
	return true;
}

void AboutState::Render(void) {
	if(!render)
		return;

	if (invalid)
		std::cout << "Not a valid key.";
	else {
		std::cout << "Zorkish :: About\n";
		std::cout << "--------------------------------------------------------\n";
		std::cout << "Written by: Rachel McQueenie\n";
		std::cout << "Press B to return to the Main Menu\n";
	}
}

void AboutState::GoBack(void) {
	game->PopState();
}

void AboutState::GoToMenu() {
	game->GoToFirstState();
}
