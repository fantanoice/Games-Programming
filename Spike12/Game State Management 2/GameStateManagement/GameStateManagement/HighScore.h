#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include "State.h"
#include "Game.h"

class HighScore : public State
{
	private:
		Game *game;
		std::string input;
		bool nameEntered;
		int score;
		int move;
	public:
		HighScore(void);
		~HighScore(void);
		HighScore(Game *g);
		void Input();
		void Update();
		void Render();
		void GoToMenu();
};

#endif

