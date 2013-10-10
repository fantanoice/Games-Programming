#ifndef ABOUTSTATE_H
#define ABOUTSTATE_H

#include "State.h"
#include "Game.h"

class AboutState : public State {
	private:
		Game *game;
		std::string input;
		bool invalid;
	public:
		AboutState(void);
		~AboutState(void);
		AboutState(Game *g);
		void Input();
		bool Update();
		void Render();
        std::string GetName();
		void GoBack();
		void GoToMenu();
};

#endif