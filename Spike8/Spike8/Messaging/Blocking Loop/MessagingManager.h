#ifndef MESSAGINGMANAGER_H
#define MESSAGINGMANAGER_H

#include <queue>
//#include <map>
#include "Mail.h"
#include "Game.h"

//class Game;
class MessagingManager {
public:
	MessagingManager(void);
	~MessagingManager(void);
	void AddMessage(Mail* m);
	void RemoveMessage();
	void SendMessages();
	void RegisterIdentifier(std::string s);
    void AddGame(Game* pGame);
private:
	std::queue<Mail *> outbound;
    Game* game;
//	std::map<std::string,int> identifers;
};

#endif

