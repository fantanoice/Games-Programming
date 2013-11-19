#ifndef GAME_H
#define GAME_H

#include "State.h"
#include <stack>
//#include "MessagingManager.h"

class MessagingManager;
class Game {
	private:
		std::stack<State*> currentState;
        MessagingManager* messagingManager;
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
		bool UpdateCurrentState();
		void EmptyGame();
		void GoToFirstState();
        void AddMessagingManager(MessagingManager *pMessagingManager);
        Mail *Receive(Mail *pMessage);
};

#endif