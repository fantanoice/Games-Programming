#ifndef STATE_H
#define STATE_H

class State
{
public:
	virtual void Input() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	inline State::State(void) {}
	inline State::~State(void) {}

};

#endif