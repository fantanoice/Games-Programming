#include "MenuState.h"
#include <iostream>
#include <string>

MenuState::MenuState(void) {
}

MenuState::~MenuState(void) {
}

MenuState::MenuState(MenuController* mh) {
	menuController = mh;
}

void MenuState::Input() {
}

void MenuState::Update() {
}

void MenuState::Render() {
	std::cout << "Zorkish :: Main Menu\n";
	std::cout << "--------------------------------------------------------\n";
	std::cout << "Welcome to Zorkish Adventures\n";
	std::cout << "1. Select Adventure and Play\n";
	std::cout << "2. Hall Of Fame\n";
	std::cout << "3. Help\n";
	std::cout << "4. About\n";
	std::cout << "5. Quit\n";
	std::cout << "Select 1-5:> _\n";
}

void MenuState::About() {
}

void MenuState::Help() {
}

void MenuState::World() {
}

void MenuState::Game() {
}

void MenuState::HallOfFame() {
}

void MenuState::Quit() {
}