#ifndef ABOUT_H
#define ABOUT_H

#include "State.h"

class About : public State {
	public:
		About(void);
		~About(void);
		void Input();
		void Update();
		void Render();
};

#endif