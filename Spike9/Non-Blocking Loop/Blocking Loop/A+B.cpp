// BlockingLoop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include <string>
#include "MainMenuState.h"
#include "conio.h"

int _tmain(int argc, _TCHAR* argv[]) {
	std::string input;
    Game *game = new Game(new MessagingManager());
	bool loop = true;
	
	// Give the game a MainMenu as its firt state
	game->PushState(new MainMenuState(game));
	
	// Initial Render before loop
	game->RenderCurrentState();

	while(loop) {
		if(kbhit())
			game->InputCurrentState();
		loop = game->UpdateCurrentState();
		game->RenderCurrentState();
	}

	// Pops and deallocates memory for any leftover states.
	game->EmptyGame();

    delete game;

	std::cout << "\n\nType something in to exit the program. This is here just to see the output.\n";
	std::cin >> input;
	return 0;
}

