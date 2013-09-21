#include "MenuState.h"
#include "GameState.h"
#include "AboutState.h"


class StateContainer {
	public:
		StateContainer();
	   ~StateContainer();
	private:
	   MenuState* menuState;
	   GameState* gameState;
	   AboutState* aboutState;
};