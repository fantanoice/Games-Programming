#include "HallOfFameState.h"
#include <iostream>

HallOfFameState::HallOfFameState(void) {}

HallOfFameState::HallOfFameState(Game *g) {
	game = g;
}

HallOfFameState::~HallOfFameState(void) {}

void HallOfFameState::Input(void) {
	std::cin >> input;
}

void HallOfFameState::Update(void) {
	if(input == "B" || input == "b") {
		input.clear();
		GoToMenu();
	}
	else {
		input.clear();
		std::cout << "Not a valid key.";
	}
}

void HallOfFameState::Render(void) {
	std::cout << "Zorkish :: Hall Of Fame\n";
	std::cout << "--------------------------------------------------------\n";
	std::cout << "Top 10 Zorkish Adventure Champions\n";
	std::cout << "1. Fred, Mountain World, 5000\n";
    std::cout << "2. Mary, Mountain World, 4000\n";
    std::cout << "3. Joe, Water World, 3000\n";
    std::cout << "4. Henry, Mountain World, 2000\n";
    std::cout << "5. Susan, Mountain World, 1000\n";
    std::cout << "6. Alfred, Water World, 900\n";
    std::cout << "7. Clark, Mountain World, 800\n";
    std::cout << "8. Harold, Mountain World, 500\n";
    std::cout << "9. Julie, Water World, 300\n";
    std::cout << "10. Bill, Box World, -5\n";
	std::cout << "Press B to return to the Main Menu\n";
}

void HallOfFameState::GoBack(void) {
	game->PopState();
}

void HallOfFameState::GoToMenu() {
	game->GoToFirstState();
}
