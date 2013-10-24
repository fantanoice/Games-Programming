#include "WaterWorldState.h"
#include <iostream>


WaterWorldState::WaterWorldState(void) {}

WaterWorldState::~WaterWorldState(void) {
	delete gameController;
}

WaterWorldState::WaterWorldState(GameController *gc) {
	gameController = gc;
	gameController->SetValidKey(true);
}

void WaterWorldState::Input(void) {
    gameController->SetInput();
}

bool WaterWorldState::Update() {
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

void WaterWorldState::Render(void) {
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

/*

Historic stuff

void WaterWorldState::GoBack(void) {
	game->PopState();
}

//#include "HighScore.h"


WaterWorldState::WaterWorldState(void) {}

WaterWorldState::~WaterWorldState(void) {
	delete gameController;
}

WaterWorldState::WaterWorldState(Game *g) {
	//game = g;
	gameController = new GameController(g);
	//valid = true;
	gameController->SetValidKey(true);
}

void WaterWorldState::Input(void) {
	std::cin >> input;
}

void WaterWorldState::Update(void) {
	if(input == "B" || input == "b")
		GoToMenu();
	else if(input == "H" || input == "h")
		GoToHighScore();
	else
		NotValid();
}

void WaterWorldState::Render(void) {
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
	input.clear();
	//valid = false;
	gameController->SetValidKey(false);
}

void WaterWorldState::GoToHighScore() {
	input.clear();
//	game->PushState(new HighScore(game));
	gameController->GoToHighScore("Water");
}

void WaterWorldState::GoToMenu() {
//	game->GoToFirstState();
	input.clear();
	gameController->GoToMenu();
}







*/
