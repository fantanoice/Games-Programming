#ifndef GAME_H
#define GAME_H

#include "State.h"
#include <stack>

class Game {
	private:
		std::stack<State*> currentState;
	protected:
		// Eventually move CurrentState functions here for friend classes.
	public:
		Game(void);
		~Game(void);
		void PopState();
		void PushState(State *state);
		State *GetCurrentState();
		void RenderCurrentState();
		void InputCurrentState();
		void UpdateCurrentState();
		void EmptyGame();
		void GoToFirstState();
};

#endif