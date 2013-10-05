#include "MountainWorldState.h"
#include <iostream>
#include "HighScore.h"

MountainWorldState::MountainWorldState(void) {}

MountainWorldState::~MountainWorldState(void) {
	delete worldController;
}

MountainWorldState::MountainWorldState(Game *g) {
	worldController = new WorldController(g);
	worldController->SetValidKey(true);
}

void MountainWorldState::Input(void) {
	std::cin >> input;
}

void MountainWorldState::Update(void) {
	if(input == "B" || input == "b")
		GoToMenu();
	else if(input == "H" || input == "h")
		GoToHighScore();
	else
		NotValid();
}

void MountainWorldState::Render(void) {
	if(!worldController->IsValidKey())
		worldController->RenderInvalidKey();	
	else {
		std::cout << "Zorkish :: Mountain World\n";
		std::cout << "--------------------------------------------------------\n";
		std::cout << "Congratulations, you win.\n";
		std::cout << "Press H to put in your score\n";
		std::cout << "Press B to return to the Main Menu\n";
	}
}

void MountainWorldState::NotValid() {
	input.clear();
	worldController->SetValidKey(false);
}

void MountainWorldState::GoToHighScore() {
	input.clear();
	worldController->GoToHighScore();
}

void MountainWorldState::GoToMenu() {
	input.clear();
	worldController->GoToMenu();
}



/*

Historic stuff

void MountainWorldState::GoBack(void) {
	game->PopState();
}

void MountainWorldState::GoToMenu() {
	game->GoToFirstState();
}*/
