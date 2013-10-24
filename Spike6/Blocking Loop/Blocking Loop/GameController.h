#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "State.h"
#include "Game.h"
#include <string>

class GameController {
	private:
		Game *game;
		bool validKey;
		std::string input;
	public:
		GameController();
		GameController(Game *g);
		~GameController();
		void GoToMenu();
		void GoToHighScore(std::string worldName);
		void SetValidKey(bool b);
		bool IsValidKey();
		void RenderInvalidKey();
        void SetInput();
		std::string GetInput();
        Game* GetGame();
        void GoToWorld(State* s);
        void NotValid();
        void Valid();
        void SetValid(bool b);
        void GoToMountainWorld();
        void GoToWaterWorld();
        void GoToBoxWorld();
};

#endif


/* Historic

	//	void SetInput(std::istream& s);

*/