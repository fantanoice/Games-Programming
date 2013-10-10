#ifndef GAME_H
#define GAME_H

#include "State.h"

class Game {
	friend class MenuController;
	friend class GameState;

	private:
		State* worldState;
		State* menuState;
		State* currentState;
	public:
		Game(void);
		~Game(void);
		void SwitchCurrentState();
};

#endif