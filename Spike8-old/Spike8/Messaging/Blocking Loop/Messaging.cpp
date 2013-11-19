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

// each class that can send or receive messages has a mailbox id, --->inc the messagingmanager?
// each class should pass reference to the messman when they are constructed


/*
Basic pseuocode

main:
    main() 
        define the messaging manager
        define game
        pass game the messaging manager

game:
    update()
        curstate->update()
        make the messmanager check if there are any messages to be sent out
        if so
            currentstate -> update(messmanager)
        else
            normal


*/

// Game -> Input()
/*
    

*/




// at the start of the state, check if there are any messages received
// if so, open them and apply the effects
// at the end of the state update, check if there are any messages to send
// if there are, send them

// these should be in game as they are not part of the main menu
// at the end of update, check for any messages
// if there are any messages, send them
// apply any messages
// clean up any sent messages