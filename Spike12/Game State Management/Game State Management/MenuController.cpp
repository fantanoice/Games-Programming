#include "MenuController.h"
#include "MenuState.h"

MenuController::~MenuController(void){
	stateContainer = new StateContainer();
}

void MenuController::Menu() {

	game->currentState = new MenuState();
}

void MenuController::About() {
}

void MenuController::Help() {
}

void MenuController::World() {
}

void MenuController::Game() {
}

void MenuController::HallOfFame() {
}

void MenuController::Quit() {
}