#ifndef MOUNTAINWORLDSTATE_H
#define MOUNTAINWORLDSTATE_H

#include "State.h"
//#include "Game.h"
#include <string>
#include "WorldController.h"

// Forward declarations
class Game;

class MountainWorldState : public State {
	private:
		Game *game;
		std::string input;
		WorldController worldController;
	public:
		MountainWorldState(void);
		~MountainWorldState(void);
		MountainWorldState(Game *g);
		void Input();
		void Update();
		void Render();
		void GoBack();
		void GoToMenu();
};

#endif