#include "WaterWorldState.h"
#include <iostream>


WaterWorldState::WaterWorldState(void) {}

WaterWorldState::~WaterWorldState(void) {
	delete gameController;
}

WaterWorldState::WaterWorldState(GameController *gc) {
	gameController = gc;
	gameController->SetValidKey(true);
	render = true;
}

void WaterWorldState::Input(void) {
    gameController->SetInput();
}

bool WaterWorldState::Update() {
	if(gameController->GetInput() == "") {
		render = false;
		NotValid();
	}
	else {
		render = true;
		if(gameController->GetInput() == "B" || gameController->GetInput() == "b") {
			Valid();
			GoToMenu();
		}
		else if(gameController->GetInput() == "H" || gameController->GetInput() == "h") {
			Valid();
			GoToHighScore();
		}
	}
	return true;
}

void WaterWorldState::Render(void) {
	if(!render)
		return;

	if(!gameController->IsValidKey())
		gameController->RenderInvalidKey();
	else {
		std::cout << "Zorkish :: Water World\n";
		std::cout << "--------------------------------------------------------\n";
		std::cout << "Congratulations, you win.\n";
		std::cout << "Press H to put in your score\n";
		std::cout << "Press B to return to the Main Menu\n";
	}
}

void WaterWorldState::NotValid() {
    gameController->NotValid();
}

void WaterWorldState::Valid() {
    gameController->Valid();
}

void WaterWorldState::GoToHighScore() {
	gameController->GoToHighScore("Water");
}

void WaterWorldState::GoToMenu() {
    gameController->GoToMenu();
}
