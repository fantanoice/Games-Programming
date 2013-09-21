#ifndef MENUSTATE_H
#define MENUSTATE_H

//#include "State.h"
#include "MenuController.h"

class MenuState : public State {
	private:
		MenuController* menuController;
	public:
		MenuState(void);
		MenuState(MenuController* mh);
		~MenuState(void);
		void Input();
		void Update();
		void Render();
		void About();
		void Help();
		void World();
		void Game();
		void HallOfFame();
		void Quit();
};

#endif