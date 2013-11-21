#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include <string>
#include "Game.h"
#include "Messenger.h"

class MainMenuState : public State, public Messenger  {
	private: 
		std::string input;
		Game *game;
		bool quit;
		bool invalid;
		bool gameSet;
		bool render;
        std::string messengerID;
        std::vector<Mail> inMail;
        void CheckBlackboard();
	public:
		MainMenuState(void);
		MainMenuState(Game *g);
		~MainMenuState(void);
		void Input();
		bool Update();
		void Render();
		void SetGame(Game *g);
		bool GoToState(State *s);
		void Send(Mail pMail);
		void Receive();
        inline bool IsMessenger() { return true; }
        void Register();
};

#endif