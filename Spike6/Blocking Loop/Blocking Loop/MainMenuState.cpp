#include "MainMenuState.h"
#include <iostream>
#include "AboutState.h"
#include "HallOfFameState.h"
#include "HelpState.h"
#include "GameState.h"

MainMenuState::MainMenuState(void) {}

MainMenuState::MainMenuState(Game *g) {
	game = g;
	quit = false;
	invalid = false;
	gameSet = true;
}

MainMenuState::~MainMenuState(void) {}

void MainMenuState::Input() {
	std::cin >> input;
}

bool MainMenuState::Update() {
	if(input == "1") {
		return GoToState(new GameState(game));
	}
	else if(input == "2") {
		return GoToState(new HallOfFameState(game));
	}
	else if(input == "3") {
		return GoToState(new HelpState(game));
	}
	else if(input == "4") {
		return GoToState(new AboutState(game));
	}
	else if(input == "5") {
		input.clear();
		quit = true;
		return false;
	}
	else {
		input.clear();
		invalid = true;
	}
	return true;
}

bool MainMenuState::GoToState(State *s)
{
	input.clear();
	if(game != NULL)
		game->PushState(s);
	else {
		//Game not set, so exit the game as it cannot continue
		gameSet = false;
		return false;
	}
	return true;
}

void MainMenuState::Render(void) {
	if (quit == true)
		std::cout << "Game quit.\n";	
	else if (invalid == true)
		std::cout << "Input isn't set to a state.\n";
	else if (gameSet != true) {
		std::cout << "Oops, you forgot to set game. Exiting.\n";
	}
	else {
		std::cout << "Zorkish :: Main Menu\n";
		std::cout << "--------------------------------------------------------\n";
		std::cout << "Welcome to Zorkish Adventures\n";
		std::cout << "1. Select Adventure and Play\n";
		std::cout << "2. Hall Of Fame\n";
		std::cout << "3. Help\n";
		std::cout << "4. About\n";
		std::cout << "5. Quit\n";
		std::cout << "Select 1-5:> _\n";
	}
}

void MainMenuState::SetGame(Game *g) {
	game = g;
}
