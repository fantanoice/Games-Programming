#ifndef WORLDCONTROLLER_H
#define WORLDCONTROLLER_H

#include "State.h"
#include "Game.h"
#include <string>


class WorldController {
	private:
		Game *game;
		bool validKey;
	public:
		WorldController();
		WorldController(Game *g);
		~WorldController();
		void GoToMenu();
		void GoToHighScore();
		void SetValidKey(bool b);
		bool IsValidKey();
		void RenderInvalidKey();
};

#endif