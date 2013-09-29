#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "Game.h"
#include <string>

class GameState : public State {
	private:
		Game *game;
		std::string input;
		bool valid;
	public:
		GameState(void);
		~GameState(void);
		GameState(Game *g);
		void Input();
		void Update();
		void Render();
		void GoBack();
		void GoToWorld(State *s);
		void GoToMenu();
};

#endif