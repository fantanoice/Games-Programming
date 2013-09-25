#include "Game.h"
#include <iostream>

Game::Game(void) {}
Game::~Game(void) {}

void Game::PopState() {
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

void Game::EmptyGame() {
	while(!currentState.empty())
		PopState();
}
