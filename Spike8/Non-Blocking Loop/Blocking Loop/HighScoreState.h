#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include "State.h"
#include "Game.h"

class HighScoreState : public State
{
	private:
		Game *game;
		std::string input;
		bool nameEntered;
		int score;
		int move;
        std::string worldName;
		bool render;
	public:
		HighScoreState(void);
		~HighScoreState(void);
        HighScoreState(Game *g, std::string wn);
		void Input();
		bool Update();
		void Render();
		void GoToMenu();
        inline bool IsMessenger() { return false;} 
};

#endif

