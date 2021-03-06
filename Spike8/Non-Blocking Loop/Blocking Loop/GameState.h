#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include <string>
#include "GameController.h"

class GameState : public State {
	private:
		GameController *gameController;
		bool render;
	public:
		GameState(void);
		~GameState(void);
		GameState(Game *g);
		void Input();
		bool Update();
		void Render();
		void GoToWorld(State *s);
		void GoToMenu();
		void GoToHighScore();
		void NotValid();
		void RenderValid();
        void Valid();
        void GoToMountainWorld();
        void GoToWaterWorld();
        void GoToBoxWorld();
        inline bool IsMessenger() { return false; }
};

#endif

/*

historic
		Game *game;
		bool valid;

		void GoBack();

        	//	std::string input;

*/