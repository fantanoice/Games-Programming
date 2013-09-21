#include "StateContainer.h"
#include <cstdio> 

StateContainer* StateContainer::stateContainer = NULL;

StateContainer::StateContainer()
{
	menuState = new MenuState();
	gameState = new GameState();
	aboutState = new AboutState();
}

StateContainer::~StateContainer()
{
	delete aboutState;
	delete gameState;
	delete menuState;
}

StateContainer* StateContainer::GetInstance()
{
	if (stateContainer == NULL) {
		stateContainer = new StateContainer();
	}
	return stateContainer;
}