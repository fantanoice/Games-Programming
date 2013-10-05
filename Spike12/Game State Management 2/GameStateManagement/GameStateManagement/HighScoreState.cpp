#include "HighScore.h"
#include <iostream>
#include <string>

HighScore::HighScore(void) {
	input = "";
	nameEntered = false;
	// Give the score and moves a default value for the sake of demonstration.
	score = 0;
	move = 0;
}

HighScore::~HighScore(void) {}

HighScore::HighScore(Game *g) {
	game = g;
	input = "";
	nameEntered = false;
	// Give the score and moves a default value for the sake of demonstration.
	score = 0;
	move = 0;
}

void HighScore::Input() {
	std::cin >> input;
}

void HighScore::Update() {
	if((input == "B" || input == "b") && nameEntered) {
		GoToMenu();
	}
	else if(input != "") {
		input.clear();
		nameEntered = true;
	}
}

void HighScore::Render() {
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
		// Todo: give world states a name
		std::cout << game->GetCurrentState()->GetName();
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

void HighScore::GoToMenu() {
	game->GoToFirstState();
}