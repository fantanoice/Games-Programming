#include "AboutState.h"
#include <iostream>


AboutState::AboutState(void)
{
}

AboutState::~AboutState(void)
{
}

AboutState::AboutState(MenuController* mc)
{
	menuController = mc;
}

void AboutState::Input(void)
{
}

void AboutState::Update(void)
{
}

void AboutState::Render(void)
{
	std::cout << "Zorkish :: About\n";
	std::cout << "--------------------------------------------------------\n";
	std::cout << "Written by: [your name here]\n";
	std::cout << "Press ESC or Enter to return to the Main Menu\n";
}