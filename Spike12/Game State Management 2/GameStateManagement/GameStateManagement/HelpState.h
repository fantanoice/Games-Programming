#ifndef HELP_H
#define HELP_H

#include "State.h"
#include "Game.h"
#include <string>

class Help : public State {
	private:
		Game *game;
		std::string input;
	public:
		Help(void);
		~Help(void);
		Help(Game *g);
		void Input();
		void Update();
		void Render();
		void GoBack();
};

#endif