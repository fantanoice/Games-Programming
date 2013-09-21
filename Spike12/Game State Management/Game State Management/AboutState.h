#ifndef ABOUTSTATE_H
#define ABOUTSTATE_H

#include "State.h"
#include "MenuController.h"

class AboutState : public State {
	private:
		MenuController* menuController;	
	public:
		AboutState(void);
		AboutState(MenuController* mc);
		~AboutState(void);
		void Input();
		void Update();
		void Render();
};

#endif