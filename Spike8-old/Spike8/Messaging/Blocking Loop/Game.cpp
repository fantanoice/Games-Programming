#include "Game.h"
#include <iostream>

Game::Game(void) {}
Game::~Game(void) {}

void Game::PopState() {
	delete currentState.top();
	currentState.pop();
}

void Game::PushState(State *state) {
	currentState.push(state);
}

State *Game::GetCurrentState() {
	if(!currentState.empty())
		return currentState.top();

	std::cout << "Something went wrong. State stack is empty.";
	exit(1);
}

void Game::RenderCurrentState() {
	currentState.top()->Render();
}

void Game::InputCurrentState() {
	currentState.top()->Input();
}

bool Game::UpdateCurrentState() {
	return currentState.top()->Update();
}

void Game::EmptyGame() {
	while(!currentState.empty())
		PopState();
}

void Game::GoToFirstState() {
	while(currentState.size() > 1)
		PopState();
}

void Game::AddMessagingManager(MessagingManager *pMessagingManager) {
    messagingManager = pMessagingManager;
}

Mail* Game::Receive(Mail* pMessage) {
    Mail* returnToSender;
    if(pMessage->GetContents()->front()->c_str == "ReceiveMessageTest") {
        std::cout << "Game has received the Message Test from " << pMessage->GetSender();
        returnToSender = new Mail("Game", pMessage->GetSender(), "Message Succeeded");
    }
    else {
        returnToSender = new Mail("Game", pMessage->GetSender(), "Message Failed");
    }
    return returnToSender;
}