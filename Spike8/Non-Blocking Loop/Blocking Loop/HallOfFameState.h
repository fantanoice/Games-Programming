#ifndef HALLOFFAMESTATE_H
#define HALLOFFAMESTATE_H

#include "State.h"
#include "Game.h"

class HallOfFameState : public State {
	private:
		Game *game;
		std::string input;
		bool invalid;
		bool render;
	public:
		HallOfFameState(void);
		~HallOfFameState(void);
		HallOfFameState(Game *g);
		void Input();
		bool Update();
		void Render();
		void GoBack();
		void GoToMenu();
        inline bool IsMessenger() { return false; }
};

#endif