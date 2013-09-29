#include "MainMenu.h"
#include <iostream>
#include "About.h"
#include "HallOfFame.h"
#include "Help.h"


MainMenu::MainMenu(void)
{
}

MainMenu::MainMenu(Game *g)
{
	game = g;
}

MainMenu::~MainMenu(void)
{
}

void MainMenu::Input(void)
{
	std::cin >> input;
}

void MainMenu::Update(void)
{
	if(input == "2") {
		input.clear();
		if(game != NULL)
			game->PushState(new HallOfFame(game));
		else {
			std::cout << "Oops, you forgot to set game.\n";
			exit(1);
		}
	}
	if(input == "3") {
		input.clear();
		if(game != NULL)
			game->PushState(new Help(game));
		else {
			std::cout << "Oops, you forgot to set game.\n";
			exit(1);
		}
	}
	else if(input == "4") {
		input.clear();
		if(game != NULL)
			game->PushState(new About(game));
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

void MainMenu::Render(void)
{
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

void MainMenu::SetGame(Game *g) {
	game = g;
}

