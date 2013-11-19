#include "HighScoreState.h"
#include <iostream>
#include <string>

HighScoreState::HighScoreState(void) {
	input = "";
	nameEntered = false;
	// Give the score and moves a default value for the sake of demonstration.
	score = 0;
	move = 0;
	render = true;
}

HighScoreState::~HighScoreState(void) {}

HighScoreState::HighScoreState(Game *g, std::string wn) {
	game = g;
	input = "";
	nameEntered = false;
	// Give the score and moves a default value for the sake of demonstration.
	score = 0;
	move = 0;
    worldName = wn;
}

void HighScoreState::Input() {
	std::cin >> input;
}

bool HighScoreState::Update() {
	if(input == "") {
		render = false;
	}
	else {
		render = true;
		if((input == "B" || input == "b") && nameEntered) {
			GoToMenu();
		}
		else if(input != "") {
			input.clear();
			nameEntered = true;
		}
	}
	return true;
}

void HighScoreState::Render() {
	if (!render)
		return;

	if(nameEntered) {
		std::cout << "Thanks, your name has been entered.\n";
		std::cout << "Press B to go to Main Menu.\n";
	}
	else {
		std::cout << "Zorkish :: New High Score\n";
		std::cout << "--------------------------------------------------------\n";
		std::cout << "Congratulations!\n";
		std::cout << "You have made it to the Zorkish Hall Of Fame\n";
		std::cout << "Adventure: ";
        std::cout << worldName;
		std::cout << "\n";
		std::cout << "Score: ";
		std::cout << score;
		std::cout << "\n";
		std::cout << "Moves: ";
		std::cout << move;
		std::cout << "\n";
		std::cout << "Please type your name and press enter:\n";
		std::cout << ":> _\n";
	}
}

void HighScoreState::GoToMenu() {
	game->GoToFirstState();
}