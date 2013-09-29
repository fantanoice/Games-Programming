#include "WaterWorldState.h"
#include <iostream>
//#include "HighScore.h"

WaterWorldState::WaterWorldState(void) {}

WaterWorldState::~WaterWorldState(void) {
	delete worldController;
}

WaterWorldState::WaterWorldState(Game *g) {
	//game = g;
	worldController = new WorldController(g);
	//valid = true;
	worldController->SetValidKey(true);
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
	if(!worldController->IsValidKey())
		worldController->RenderInvalidKey();
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
	worldController->SetValidKey(false);
}

void WaterWorldState::GoToHighScore() {
	input.clear();
//	game->PushState(new HighScore(game));
	worldController->GoToHighScore();
}

void WaterWorldState::GoToMenu() {
//	game->GoToFirstState();
	input.clear();
	worldController->GoToMenu();
}

/*

Historic stuff

void WaterWorldState::GoBack(void) {
	game->PopState();
}
*/
