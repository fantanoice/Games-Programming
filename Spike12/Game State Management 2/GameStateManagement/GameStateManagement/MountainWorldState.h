#ifndef MOUNTAINWORLDSTATE_H
#define MOUNTAINWORLDSTATE_H

#include "State.h"
#include <string>
#include "WorldController.h"

// Forward declarations
class Game;

class MountainWorldState : public State {
	private:
		std::string input;
		WorldController *worldController;
	public:
		MountainWorldState(void);
		~MountainWorldState(void);
		MountainWorldState(Game *g);
		void Input();
		void Update();
		void Render();
		void GoToMenu();
		void GoToHighScore();
		void NotValid();
};

#endif