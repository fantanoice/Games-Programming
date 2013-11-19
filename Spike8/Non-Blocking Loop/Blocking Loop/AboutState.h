#ifndef ABOUTSTATE_H
#define ABOUTSTATE_H

#include "State.h"
#include "Game.h"
#include "Messenger.h"

class AboutState : public State, public Messenger  {
	private:
		Game *game;
		std::string input;
		bool invalid;
		bool render;
        std::vector<Mail> inMail;
        std::string messengerID;
	public:
		AboutState(void);
		~AboutState(void);
		AboutState(Game *g);
		void Input();
		bool Update();
		void Render();
        std::string GetName();
		void GoBack();
		void GoToMenu();
		void Send(Mail pMail);
		void Receive();
        inline bool IsMessenger() { return true; }
        void Register();
};

#endif