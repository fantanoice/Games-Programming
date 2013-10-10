// GameStateManagement.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include <string>
#include "MainMenuState.h"

int _tmain(int argc, _TCHAR* argv[]) {
	std::string input;
	Game game;
	
	// Give the game a MainMenu as its firt state
	game.PushState(new MainMenuState(&game));
	
	// This is just to demonstrate the changing of states. This will be converted to a game loop at a later date.
	game.RenderCurrentState();
	game.InputCurrentState();
	game.UpdateCurrentState();
	game.RenderCurrentState();
	game.InputCurrentState();
	game.UpdateCurrentState();
	game.RenderCurrentState();
	game.InputCurrentState();
	game.UpdateCurrentState();
	game.RenderCurrentState();
	game.InputCurrentState();
	game.UpdateCurrentState();
	game.RenderCurrentState();
	game.InputCurrentState();
	game.UpdateCurrentState();
	game.RenderCurrentState();
	game.InputCurrentState();
	game.UpdateCurrentState();
	game.RenderCurrentState();

	// Pops and deallocates memory for any leftover states.
	game.EmptyGame();

	std::cout << "\n\nType something in to exit the program. This is here just to see the output.\n";
	std::cin >> input;
	return 0;
}

