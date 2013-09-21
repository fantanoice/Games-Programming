//#include "Game.h"

//#include "GameState.h"

#include "MenuController.h"
#include <iostream>
#include <string>

int main(int argc, char *argv[], char *envp[]) {
	std::string input;

	Game* game = new Game();
	MenuController* menuController = new MenuController(game);
	delete menuController;
	delete game;
	std::cout << "Input something to end the program. This is only here so we can see the program run.\n";
	std::cin >> input;
	input.clear();

	return 0;
}