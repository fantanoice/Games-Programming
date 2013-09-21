#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H

#include "Game.h"
#include "StateContainer.h"

class MenuController {
	private:
		Game* game;
		StateContainer stateContainer;
	public:
		inline MenuController::MenuController(Game* g)	{this->game = g;} // Wouldn't let me get around this inline
		~MenuController(void);
		void Menu();
		void About();
		void Help();
		void World();
		void Game();
		void HallOfFame();
		void Quit();
};

#endif

