#ifndef MAINMENU_H
#define MAINMENU_H

#include "MainMenu.h"
#include <string>
#include "Game.h"

class MainMenu : public State {
	private: 
		std::string input;
		Game *game;
	public:
		MainMenu(void);
		MainMenu(Game *g);
		~MainMenu(void);
		void Input();
		void Update();
		void Render();
		void SetGame(Game *g);
};

#endif