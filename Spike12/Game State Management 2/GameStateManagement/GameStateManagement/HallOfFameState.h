#ifndef HALLOFFAME_H
#define HALLOFFAME_H

#include "State.h"
#include "Game.h"
#include <string>

class HallOfFame : public State {
	private:
		Game *game;
		std::string input;
	public:
		HallOfFame(void);
		~HallOfFame(void);
		HallOfFame(Game *g);
		void Input();
		void Update();
		void Render();
		void GoBack();
};

#endif