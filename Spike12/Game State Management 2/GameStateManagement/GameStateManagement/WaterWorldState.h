#ifndef WATERWORLDSTATE_H
#define WATERWORLDSTATE_H

#include "State.h"
//#include "Game.h"
#include <string>
#include "GameController.h"

// Forward declarations
class Game;

class WaterWorldState : public State {
	private:
	//	Game *game;
		GameController *gameController;
		std::string input;
	//	bool valid;
	public:
		WaterWorldState(void);
		~WaterWorldState(void);
		WaterWorldState(Game *g);
		void Input();
		void Update();
		void Render();
		void GoToMenu();
		void GoToHighScore();
		void NotValid();
};

#endif