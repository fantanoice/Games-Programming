#include "Game.h"
#include <iostream>
#include <string>

Game::Game(void)
{
}

Game::~Game(void)
{
}

void Game::SwitchCurrentState()
{
	if(currentState == worldState)
		currentState = menuState;
	else if(currentState == menuState)
		currentState = worldState;
	else {
		std::cout << "Oops, the current state is not the current menu or world state.";
		exit(1);
	}
}
