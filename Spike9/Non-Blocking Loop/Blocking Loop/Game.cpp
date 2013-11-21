#include "Game.h"
#include <iostream>

Game::Game(MessagingManager *pMessagingManager) {
    messagingManager = pMessagingManager;
    announcer = new Announcer(messagingManager);
    announcer->AddSubscriber("AboutState");
    announcer->AddSubscriber("MainMenuState");
    announcer->Announce("Game has started. Letting the subscribers know.");
}

Game::~Game(void) {
    delete messagingManager;
    delete announcer;
}

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
