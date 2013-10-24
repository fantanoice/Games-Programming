#include "MountainWorldState.h"
#include <iostream>

MountainWorldState::MountainWorldState(void) {}

MountainWorldState::~MountainWorldState(void) {
	delete gameController;
}

MountainWorldState::MountainWorldState(GameController *gc) {
	gameController = gc;
	gameController->SetValidKey(true);
}

void MountainWorldState::Input(void) {
    gameController->SetInput();
}

bool MountainWorldState::Update() {
	if(gameController->GetInput() == "B" || gameController->GetInput() == "b") {
		Valid();
        GoToMenu();
    }
	else if(gameController->GetInput() == "H" || gameController->GetInput() == "h") {
		Valid();
        GoToHighScore();
    }
	else
		NotValid();
	return true;
}

void MountainWorldState::Render(void) {
	if(!gameController->IsValidKey())
		gameController->RenderInvalidKey();	
	else {
		std::cout << "Zorkish :: Mountain World\n";
		std::cout << "--------------------------------------------------------\n";
		std::cout << "Congratulations, you win.\n";
		std::cout << "Press H to put in your score\n";
		std::cout << "Press B to return to the Main Menu\n";
	}
}

void MountainWorldState::NotValid() {
    gameController->NotValid();
}

void MountainWorldState::Valid() {
    gameController->Valid();
}

void MountainWorldState::GoToHighScore() {
	gameController->GoToHighScore("Mountain");
}

void MountainWorldState::GoToMenu() {
	gameController->GoToMenu();
}

/*

Historic stuff

void MountainWorldState::GoBack(void) {
	game->PopState();
}

void MountainWorldState::GoToMenu() {
	game->GoToFirstState();
}

MountainWorldState::MountainWorldState(Game *g) {
	gameController = new GameController(g);
	gameController->SetValidKey(true);
}


void MountainWorldState::Input(void) {
	std::cin >> input;
}

*/
