#include "MessagingManager.h"

#include <iostream>

MessagingManager::MessagingManager(void) {}

MessagingManager::~MessagingManager(void) {}

void MessagingManager::AddMessage(Mail* m) {
	outbound.push(m);
}

void MessagingManager::RemoveMessage() {
	outbound.pop();
}

void MessagingManager::SendMessages() {
	while(!outbound.empty()) {
        while(!outbound.front()->GetContents()->empty()) {
            while(!outbound.front()->GetReceivers()->empty()) {
                if(outbound.front()->GetReceivers()->front()->c_str() == "Game")
                   // game->Receive(outbound.front()->GetContents()->front());
                       std::cout << "Welp";
            }
        }
        RemoveMessage();
	}
}

void MessagingManager::RegisterIdentifier(std::string s) {

}

void MessagingManager::AddGame(Game* pGame) {
    game = pGame;
}