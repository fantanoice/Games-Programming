#include "HelpState.h"
#include <iostream>

HelpState::HelpState(void) {}

HelpState::HelpState(Game *g) {
	game = g;
	invalid = false;
}

HelpState::~HelpState(void) {}

void HelpState::Input(void) {
	std::cin >> input;
}

bool HelpState::Update() {
	if(input == "B" || input == "b") {
		input.clear();
		GoToMenu();
	}
	else {
		input.clear();
		invalid = true;
	}
	return true;
}

void HelpState::Render(void) {
	if(invalid)
		std::cout << "Not a valid key.";
	else {
		std::cout << "Zorkish :: Help\n";
		std::cout << "--------------------------------------------------------\n";
		std::cout << "The following commands are supported:\n";
		std::cout << "If this is phase 1 development show the following:\n";
		std::cout << "quit,\n";
		std::cout << "hiscore,\n";
		std::cout << "[go] _, (or just n, ne, e, etc)\n";
		std::cout << "look at _,\n";
		std::cout << "look in _,\n";
		std::cout << "inventory,\n";
		std::cout << "open _ [with _],\n";
		std::cout << "close _,\n";
		std::cout << "attack _ with _,\n";
		std::cout << "take _ [from _],\n";
		std::cout << "put _ in _,\n";
		std::cout << "drop _,\n";
		std::cout << "quit,\n";
		std::cout << "[up arrow] to repeat last command\n";
		std::cout << "\n";
		std::cout << "We lied, none of these are supported. Have fun!\n";
		std::cout << "Press B to return to the Main Menu\n";
	}
}

void HelpState::GoBack(void) {
	game->PopState();
}

void HelpState::GoToMenu() {
	game->GoToFirstState();
}