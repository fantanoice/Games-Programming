#ifndef WATERWORLDSTATE_H
#define WATERWORLDSTATE_H

#include "State.h"
#include "GameController.h"

class WaterWorldState : public State {
	private:
		GameController *gameController;
		bool render;
	public:
		WaterWorldState(void);
		~WaterWorldState(void);
        WaterWorldState::WaterWorldState(GameController *gc);
		void Input();
		bool Update();
		void Render();
		void GoToMenu();
		void GoToHighScore();
		void NotValid();
        void Valid();
        inline bool IsMessenger() { return false; }
};

#endif
