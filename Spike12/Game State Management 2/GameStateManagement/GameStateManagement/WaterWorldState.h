#ifndef WATERWORLDSTATE_H
#define WATERWORLDSTATE_H

#include "State.h"
#include "GameController.h"

class WaterWorldState : public State {
	private:
		GameController *gameController;
	public:
		WaterWorldState(void);
		~WaterWorldState(void);
        WaterWorldState::WaterWorldState(GameController *gc);
		void Input();
		void Update();
		void Render();
		void GoToMenu();
		void GoToHighScore();
		void NotValid();
        void Valid();
};

#endif

/*

Historic

	//	Game *game;

    	//	bool valid;

    //#include "Game.h"

    		std::string input;
*/