#ifndef BOXWORLDSTATE_H
#define BOXWORLDSTATE_H

#include "State.h"
#include "GameController.h"

class BoxWorldState : public State {
	private:
		GameController *gameController;
	public:
		BoxWorldState(void);
		~BoxWorldState(void);
        BoxWorldState::BoxWorldState(GameController *gc);
		void Input();
		void Update();
		void Render();
		void GoToMenu();
		void GoToHighScore();
		void NotValid();
        void Valid();
};

#endif