#ifndef GAME_H
#define GAME_H

#include "State.h"
#include <stack>
#include "MessagingManager.h"
#include "Announcer.h"

class Game {
	private:
		std::stack<State*> currentState;
        MessagingManager *messagingManager;
        Announcer* announcer;
	protected:
		// Eventually move CurrentState functions here for friend classes.
	public:
		Game(MessagingManager *pMessagingManager);
		~Game(void);
		void PopState();
		void PushState(State *state);
		State *GetCurrentState();
		void RenderCurrentState();
		void InputCurrentState();
		bool UpdateCurrentState();
		void EmptyGame();
		void GoToFirstState();
        inline MessagingManager *GetMessagingManager() { return messagingManager; }
};

#endif