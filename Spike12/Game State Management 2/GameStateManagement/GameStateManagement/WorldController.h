#ifndef WORLDCONTROLLER_H
#define WORLDCONTROLLER_H

#include "State.h"
#include "Game.h"
#include <string>


class WorldController {
	public:
		WorldController();
		WorldController(Game *g);
		~WorldController();
		void GoToMenu();
};

#endif