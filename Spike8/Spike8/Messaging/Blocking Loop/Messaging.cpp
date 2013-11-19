// BlockingLoop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include <string>
#include "MainMenuState.h"
//#include "MessagingManager.h"
#include "conio.h"

int _tmain(int argc, _TCHAR* argv[]) {
	std::string input;
	Game game;
	bool loop = true;
	int tick = 0;
    MessagingManager* messagingManager = new MessagingManager();
	
    game.AddMessagingManager(messagingManager);
    

	// Give the game a MainMenu as its firt state

    //std::queue<std::string*>* contents;
    //std::string = "MainMenuState"
    //game.Send(new Message("Game","PushState","MainMenuState", &game);
    // dont need to worry about this, just game talking to itself
	game.PushState(new MainMenuState(&game));
	
	// Initial Render before loop
    //game.Send("RenderCurrentState","MainMenuState");
	game.RenderCurrentState();

	while(loop) {
		tick++;

		if(kbhit())
			game.InputCurrentState();
		loop = game.UpdateCurrentState();
		game.RenderCurrentState();

		if(tick % 5000 == 0)
			std::cout << "\nTicking along...\n";
	}

	// Pops and deallocates memory for any leftover states.
	game.EmptyGame();

	std::cout << "\n\nType something in to exit the program. This is here just to see the output.\n";
	std::cin >> input;
	return 0;
}

