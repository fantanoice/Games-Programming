#ifndef MOUNTAINWORLDSTATE_H
#define MOUNTAINWORLDSTATE_H

#include "State.h"
#include "GameController.h"

class MountainWorldState : public State {
	private:
		GameController *gameController;
		bool render;
	public:
		MountainWorldState(void);
		~MountainWorldState(void);
        MountainWorldState::MountainWorldState(GameController *gc);
		void Input();
		bool Update();
		void Render();
		void GoToMenu();
		void GoToHighScore();
		void NotValid();
        void Valid();
        inline bool IsMessenger() { return false; }
};

#endif


/* Historic

		MountainWorldState(Game *g);
        		std::string input;
*/