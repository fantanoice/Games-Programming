#ifndef GAMESTATE_H
#define GAMESTATE_H

//#include "MenuState.h"
#include "State.h"
//#include "MenuController.h"
//#include "Game.h"

class GameState : public State {
	private:
//		MenuController* menuController;	
	public:
		GameState(void);
//		GameState::GameState(MenuController* mh);   ----should it have a menucontroller to go back to the menu?
		~GameState(void);
		void Input();
		void Update();
		void Render();
};

#endif