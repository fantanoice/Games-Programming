#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include <string>
#include "Game.h"

class MainMenuState : public State {
	private: 
		std::string input;
		Game *game;
		bool quit;
		bool invalid;
		bool gameSet;
		bool render;
	public:
		MainMenuState(void);
		MainMenuState(Game *g);
		~MainMenuState(void);
		void Input();
		bool Update();
		void Render();
		void SetGame(Game *g);
		bool GoToState(State *s);
};

#endif