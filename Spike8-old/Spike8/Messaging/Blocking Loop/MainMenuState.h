#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include <string>
#include "Game.h"

class MainMenuState : public State, public Messenger  {
	private: 
		std::string input;
		Game *game;
		bool quit;
		bool invalid;
		bool gameSet;
		bool render;
        MessagingManager* messagingManager;
	public:
		MainMenuState(void);
		MainMenuState(Game *pGame, MessagingManager* pMessagingManager);
		~MainMenuState(void);
		void Input();
		bool Update();
		void Render();
		void SetGame(Game *g);
		bool GoToState(State *s);

		void Send(Mail* pMessage);
		void Receive(Mail* pMessage);
        inline bool IsMessenger() { return true; }
};

#endif