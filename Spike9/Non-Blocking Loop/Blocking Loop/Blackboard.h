#ifndef BLACKBOARD_H
#define BLACKBOARD_H

#include "Messenger.h"
#include "MessagingManager.h"

class Blackboard: public Messenger {
public:
    Blackboard(MessagingManager* pMessagingManager);
    ~Blackboard(void);
    void Send(Mail pMail);
	void Receive();
    void Register();
    void GenerateListenerMail(std::string pContents, std::vector<std::string> pListeners);
    void SendListenerMail(std::string pListener);
    void Update();
private:
    MessagingManager* messagingManager;
    std::vector<Mail> inMail;
    std::string messengerID;
    std::vector<Mail> listenerMail;
};

#endif