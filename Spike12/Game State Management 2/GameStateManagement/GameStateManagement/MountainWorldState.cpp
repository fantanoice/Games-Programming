#include "MountainWorldState.h"
#include <iostream>
#include "HighScore.h"

MountainWorldState::MountainWorldState(void) {}

MountainWorldState::~MountainWorldState(void) {}

MountainWorldState::MountainWorldState(Game *g) {
	game = g;
//	worldController = new WorldController(g);
}

void MountainWorldState::Input(void) {
	std::cin >> input;
}

void MountainWorldState::Update(void) {
	if(input == "B" || input == "b") {
		input.clear();
		GoToMenu();
	}
	else if(input == "H" || input == "h") {
		input.clear();
		game->PushState(new HighScore(game));
	}
	else {
		input.clear();
		std::cout << "Not a valid key.";
	}
}

void MountainWorldState::Render(void) {
	std::cout << "Zorkish :: MountainWorld\n";
	std::cout << "--------------------------------------------------------\n";
	std::cout << "Nothing here yet.\n";
	std::cout << "Press H to go to the High Score page.\n";
	std::cout << "Press B to return to the Main Menu\n";
}



/*

Historic stuff
*/
void MountainWorldState::GoBack(void) {
	game->PopState();
}

void MountainWorldState::GoToMenu() {
	game->GoToFirstState();
}
