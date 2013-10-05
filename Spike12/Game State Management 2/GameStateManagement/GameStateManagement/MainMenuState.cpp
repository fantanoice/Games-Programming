#include "MainMenuState.h"
#include <iostream>
#include "AboutState.h"
#include "HallOfFameState.h"
#include "HelpState.h"
#include "GameState.h"

MainMenuState::MainMenuState(void) {}

MainMenuState::MainMenuState(Game *g) {
	game = g;
}

MainMenuState::~MainMenuState(void) {}

void MainMenuState::Input(void) {
	std::cin >> input;
}

void MainMenuState::Update(void) {
	if(input == "1") {
		input.clear();
		if(game != NULL)
			game->PushState(new GameState(game));
		else {
			std::cout << "Oops, you forgot to set game.\n";
			exit(1);
		}
	}
	else if(input == "2") {
		input.clear();
		if(game != NULL)
			game->PushState(new HallOfFameState(game));
		else {
			std::cout << "Oops, you forgot to set game.\n";
			exit(1);
		}
	}
	else if(input == "3") {
		input.clear();
		if(game != NULL)
			game->PushState(new HelpState(game));
		else {
			std::cout << "Oops, you forgot to set game.\n";
			exit(1);
		}
	}
	else if(input == "4") {
		input.clear();
		if(game != NULL)
			game->PushState(new AboutState(game));
		else {
			std::cout << "Oops, you forgot to set game.\n";
			exit(1);
		}
	}
	else if(input == "5") {
		std::cout << "Game quit. Just keep hitting 5. This will be better when the game loop is implemented.\n";
		return;
	}
	else {
		input.clear();
		std::cout << "Input isn't set to a state.\n";
	}
}

void MainMenuState::Render(void) {
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

void MainMenuState::SetGame(Game *g) {
	game = g;
}
