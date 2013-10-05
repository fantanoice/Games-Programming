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
		void GoToHighScore();
		void SetValidKey(bool b);
		bool IsValidKey();
		void RenderInvalidKey();
		void SetInput(std::string s);
		std::string GetInput();
};

#endif