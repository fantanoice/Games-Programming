#include "MainMenuState.h"
#include <iostream>
#include "AboutState.h"
#include "HallOfFameState.h"
#include "HelpState.h"
#include "GameState.h"

MainMenuState::MainMenuState(void) {}

MainMenuState::MainMenuState(Game *g) {
	game = g;
	quit = false;
	invalid = false;
	gameSet = true;
	render = true;
    messengerID = "MainMenuState";
    Register();
}

MainMenuState::~MainMenuState(void) {}

void MainMenuState::Input() {
	std::cin >> input;
}

bool MainMenuState::Update() {
    CheckBlackboard();

    Receive();

    for(std::vector<int>::size_type i = 0; i != inMail.size(); i++) {
        std::cout << messengerID + " Mail = " + (inMail.begin() + i)->GetContents() + "\n";
    }
    inMail.erase(inMail.begin(),inMail.end());

    if(input == "") {
		input.clear();
		render = false;
	}
	else {
		render = true;
		if(input == "1") {
			return GoToState(new GameState(game));
		}
		else if(input == "2") {
			return GoToState(new HallOfFameState(game));
		}
		else if(input == "3") {
			return GoToState(new HelpState(game));
		}
		else if(input == "4") {
			return GoToState(new AboutState(game));
		}
		else if(input == "5") {
			input.clear();
			quit = true;
			// Returns false so the loop can break
			return false;
		}
		else if(input != "") {
			input.clear();
			invalid = true;
			input = "";
		}
	}
	return true;
}

void MainMenuState::CheckBlackboard() {
    Mail *mail = new Mail(messengerID,"Blackboard","Blackboard|" + messengerID);
    Send(*mail);
    delete mail;
}

bool MainMenuState::GoToState(State *s) {
	input.clear();
	if(game != NULL)
		game->PushState(s);
	else {
		//Game not set, so exit the game as it cannot continue
		gameSet = false;
		return false;
	}
	return true;
}

void MainMenuState::Render(void) {
	if(!render)
		return;

	if (quit) {
		std::cout << "Game quit.\n";
	}
	else if (invalid) {
		std::cout << "Input isn't set to a state.\n";
	}
	else if (!gameSet && render) {
		std::cout << "Oops, you forgot to set game. Exiting.\n";
	}
	else {
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
}

void MainMenuState::SetGame(Game *g) {
	game = g;
}

void MainMenuState::Send(Mail pMail) {
    game->GetMessagingManager()->Add(pMail);
}
void MainMenuState::Receive() {
    std::vector<Mail> tempMail = game->GetMessagingManager()->MailForID(messengerID);
    if(!tempMail.empty())
        inMail.insert(inMail.end(), tempMail.begin(), tempMail.end());
}

void MainMenuState::Register() {
    game->GetMessagingManager()->RegisterID(messengerID);
}