// GameStateManagement.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "About.h"
#include "Game.h"
#include <iostream>
#include <string>


int _tmain(int argc, _TCHAR* argv[])
{
	std::string input;

	About *about = new About();
	Game game;
	game.PushState(about);
	game.RenderCurrentState();
	game.EmptyGame();
	delete about;

	std::cout << "\n\nType something in to exit the program. This is here just to see the output.\n";
	std::cin >> input;
	return 0;
}

