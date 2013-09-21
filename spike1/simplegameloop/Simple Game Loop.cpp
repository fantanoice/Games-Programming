// Simple Game Loop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#define MINSIDE 0
#define MAXSIDE 8

void update(std::string grid[][MAXSIDE], int &curX, int &curY, bool &loop, bool &valid, std::string &direction, bool &won, bool &lost, bool &quit);
bool isWall(std::string grid[][MAXSIDE], int newX, int newY);
bool outOfBoundary(int newXY);
void render(bool &valid, std::string &direction, bool &won, bool &lost, bool &quit);
void drawGrid(std::string grid[][MAXSIDE]);
void drawIntro();
void input(std::string &input, std::string grid[][MAXSIDE], int &curX, int &curY, bool &valid, bool &loop, std::string &direction, bool &quit);
void useInput(std::string &input, std::string grid[][MAXSIDE], int &curX, int &curY, bool &valid, bool &loop, std::string &direction, bool &quit);

int _tmain(int argc, _TCHAR* argv[])
{
	std::string grid[MAXSIDE][MAXSIDE] = { 
		{ "#", "#", "#", "#", "#", "#", "#", "#" }, 
		{ "#", "G", " ", "D", "#", "D", " ", "#" },
		{ "#", " ", " ", " ", "#", " ", " ", "#" },
		{ "#", "#", "#", " ", "#", " ", "D", "#" },
		{ "#", " ", " ", " ", "#", " ", " ", "#" },
		{ "#", " ", "#", "#", "#", "#", " ", "#" },
		{ "#", " ", " ", " ", " ", " ", " ", "#" },
		{ "#", "#", "S", "#", "#", "#", "#", "#" }
	};

	int curX = 2; // because array 0 indexed
	int curY = 7;
	bool loop = true;
	bool valid;
	std::string direction;
	bool won = false;
	bool lost = false;
	bool quit = false;
	std::string userInput;

	drawGrid(grid);
	drawIntro();

	do {
		input(userInput, grid, curX, curY, valid, loop, direction, quit);
		update(grid, curX, curY, loop, valid, direction, won, lost, quit);
		render(valid, direction, won, lost, quit);
	} while(loop);
	
	return 0;
}

void input(std::string &userInput, std::string grid[][MAXSIDE], int &curX, int &curY, bool &valid, bool &loop, std::string &direction, bool &quit) {
	std::cin >> userInput;
	useInput(userInput, grid, curX, curY, valid, loop, direction, quit);
	userInput.clear();
}

void update(std::string grid[][MAXSIDE], int &curX, int &curY, bool &loop, bool &valid, std::string &direction, bool &won, bool &lost, bool &quit) {
	int oldX = curX;
	int oldY = curY;

	if(quit == true)
		return;
	
	if(grid[curY][curX] == "D") {
		lost = true;
		loop = false;
	}
	else if(grid[curY][curX] == "G") {
		won = true;
		loop = false;
	}
	else {
		grid[oldY][oldX] = " ";
		grid[curY][curX] = "S";
	}
}

bool isWall(std::string grid[][MAXSIDE], int newX, int newY) {
	if (grid[newY][newX] == "#")
		return true;
	return false;
}

bool outOfBoundary(int newXY) {
	if(newXY < MINSIDE || newXY > MAXSIDE - 1)
		return true;
	return false;
}

void render(bool &valid, std::string &direction, bool &won, bool &lost, bool &quit) {
	if(!valid)
		std::cout << "Not a valid input, please try again.\n";
	else if (lost)
		std::cout << "Game over\n";
	else if (won)
		std::cout << "You win!\n";
	else if (quit)
		std::cout << "Game Quit\n";
	else
		std::cout << "Moved " << direction << "\n";
}

void drawGrid(std::string grid[][MAXSIDE]) {
	for(int i = 0 ; i < MAXSIDE ; i++) {
		for(int j = 0 ; j < MAXSIDE ; j++)
			std::cout << grid[i][j];
		std::cout << "\n";
	}
}

void drawIntro() {
	std::cout << "Do you want to move North (N), East (E), South (S), West (W) or Quit (Q)?\n";
}

void useInput(std::string &userInput, std::string grid[][MAXSIDE], int &curX, int &curY, bool &valid, bool &loop, std::string &direction, bool &quit) {
	if((userInput == "N" || userInput == "n") && (!outOfBoundary(curY - 1))) {
		if (!isWall(grid, curX, curY - 1)) {
			valid = true;
			curY = curY - 1;
			direction = "North";
		}
		else
			valid = false;
	}
	else if ((userInput == "E" || userInput == "e") && (!outOfBoundary(curX - 1))) {
		if (!isWall(grid, curX + 1, curY)) {
			valid = true;
			curX = curX + 1;
			direction = "East";
		}
		else
			valid = false;
	}
	else if ((userInput == "S" || userInput == "s") && (!outOfBoundary(curY + 1))) {
		if (!isWall(grid, curX, curY + 1)) {
			valid = true;
			curY = curY + 1;
			direction = "South";
		}
		else
			valid = false;
	}
	else if ((userInput == "W" || userInput == "w") && (!outOfBoundary(curX + 1))) {
		if (!isWall(grid, curX - 1, curY)) {
			valid = true;
			curX = curX - 1;
			direction = "West";
		}
		else
			valid = false;
	}
	else if (userInput == "Q" || userInput == "q") {
		valid = true;
		quit = true;
		loop = false;
	}
	else
		valid = false;
}