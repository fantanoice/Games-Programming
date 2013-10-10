#ifndef HELPSTATE_H
#define HELPSTATE_H

#include "State.h"
#include "Game.h"

class HelpState : public State {
	private:
		Game *game;
		std::string input;
	public:
		HelpState(void);
		~HelpState(void);
		HelpState(Game *g);
		void Input();
		void Update();
		void Render();
		void GoBack();
		void GoToMenu();
};

#endif