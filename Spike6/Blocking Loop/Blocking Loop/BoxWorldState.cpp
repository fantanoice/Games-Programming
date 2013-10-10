#include "BoxWorldState.h"
#include <iostream>

BoxWorldState::BoxWorldState(void) {}

BoxWorldState::~BoxWorldState(void) {
	delete gameController;
}

BoxWorldState::BoxWorldState(GameController *gc) {
	gameController = gc;
	gameController->SetValidKey(true);
}

void BoxWorldState::Input(void) {
    gameController->SetInput();
}

bool BoxWorldState::Update() {
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

void BoxWorldState::Render(void) {
	if(!gameController->IsValidKey())
		gameController->RenderInvalidKey();	
	else {
		std::cout << "Zorkish :: Box World\n";
		std::cout << "--------------------------------------------------------\n";
		std::cout << "Congratulations, you win.\n";
		std::cout << "Press H to put in your score\n";
		std::cout << "Press B to return to the Main Menu\n";
	}
}

void BoxWorldState::NotValid() {
    gameController->NotValid();
}

void BoxWorldState::Valid() {
    gameController->Valid();
}

void BoxWorldState::GoToHighScore() {
	gameController->GoToHighScore("Box");
}

void BoxWorldState::GoToMenu() {
	gameController->GoToMenu();
}