#ifndef ABOUTSTATE_H
#define ABOUTSTATE_H

#include "State.h"
#include "Game.h"
#include <string>

class AboutState : public State {
	private:
		Game *game;
		std::string input;
	public:
		AboutState(void);
		~AboutState(void);
		AboutState(Game *g);
		void Input();
		void Update();
		void Render();
		void GoBack();
		void GoToMenu();
};

#endif