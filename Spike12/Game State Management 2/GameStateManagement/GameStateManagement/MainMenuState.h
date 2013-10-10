#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include <string>
#include "Game.h"

class MainMenuState : public State {
	private: 
		std::string input;
		Game *game;
	public:
		MainMenuState(void);
		MainMenuState(Game *g);
		~MainMenuState(void);
		void Input();
		void Update();
		void Render();
		void SetGame(Game *g);
};

#endif