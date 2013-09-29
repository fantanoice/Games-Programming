#include "HallOfFame.h"
#include <iostream>

HallOfFame::HallOfFame(void)
{
}

HallOfFame::HallOfFame(Game *g)
{
	game = g;
}

HallOfFame::~HallOfFame(void)
{
}

void HallOfFame::Input(void)
{
	std::cin >> input;
}

void HallOfFame::Update(void)
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

void HallOfFame::Render(void)
{
	std::cout << "Zorkish :: Hall Of Fame\n";
	std::cout << "--------------------------------------------------------\n";
	std::cout << "I dunno, stuff.\n";
	std::cout << "Press B to return to the Main Menu\n";
}

void HallOfFame::GoBack(void)
{
	game->PopState();
}