#ifndef STATE_H
#define STATE_H

#include <string>

class State {
	public:
		virtual void Input() = 0;
		virtual bool Update() = 0;
		virtual void Render() = 0;
        virtual bool IsMessenger() = 0;
};

#endif