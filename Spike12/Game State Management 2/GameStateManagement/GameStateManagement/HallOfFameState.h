#ifndef HALLOFFAMESTATE_H
#define HALLOFFAMESTATE_H

#include "State.h"
#include "Game.h"
#include <string>

class HallOfFameState : public State {
	private:
		Game *game;
		std::string input;
	public:
		HallOfFameState(void);
		~HallOfFameState(void);
		HallOfFameState(Game *g);
		void Input();
		void Update();
		void Render();
		void GoBack();
		void GoToMenu();
};

#endif