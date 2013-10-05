#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
//#include "Game.h"
#include <string>
#include "GameController.h"

// Forward declarations
class Game;

class GameState : public State {
	private:
	//	std::string input;
		GameController *gameController;
	public:
		GameState(void);
		~GameState(void);
		GameState(Game *g);
		void Input();
		void Update();
		void Render();
		void GoToWorld(State *s);
		void GoToMenu();
		void GoToHighScore();
		void NotValid();
		void RenderValid();
};

#endif

/*

historic
		Game *game;
		bool valid;

		void GoBack();

*/