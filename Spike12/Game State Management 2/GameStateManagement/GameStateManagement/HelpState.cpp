#include "Help.h"
#include <iostream>

Help::Help(void)
{
}

Help::Help(Game *g)
{
	game = g;
}

Help::~Help(void)
{
}

void Help::Input(void)
{
	std::cin >> input;
}

void Help::Update(void)
{
	if(input == "B" || input == "b") {
		input.clear();
		GoBack();
	}
	else {
		input.clear();
		std::cout << "Not a valid key.";
	}
}

void Help::Render(void)
{
	std::cout << "Zorkish :: Help\n";
	std::cout << "--------------------------------------------------------\n";
	std::cout << "Helpy help.\n";
	std::cout << "Press B to return to the Main Menu\n";
}

void Help::GoBack(void)
{
	game->PopState();
}