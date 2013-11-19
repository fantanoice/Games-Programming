#ifndef ABOUTSTATE_H
#define ABOUTSTATE_H

#include "State.h"
#include "Game.h"
#include "MessagingManager.h"

class Messenger {};
class AboutState : public State, public Messenger {
	private:
		Game *game;
		std::string input;
		bool invalid;
		bool render;
		MessagingManager* messagingManager;
	public:
		AboutState(void);
		~AboutState(void);
		AboutState(Game* pGame, MessagingManager* pMessagingManager);
		void Input();
		bool Update();
		void Render();
        std::string GetName();
		void GoBack();
		void GoToMenu();
		void MessageTest();

		void Send(Mail* pMessage);
		void Receive(Mail* pMessage);
};

#endif