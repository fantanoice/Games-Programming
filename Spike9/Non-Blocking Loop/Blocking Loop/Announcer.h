#ifndef ANNOUNCER_H
#define ANNOUNCER_H

#include "Messenger.h"
#include "MessagingManager.h"

class Announcer: public Messenger {
public:
    Announcer(MessagingManager* pMessagingManager);
    ~Announcer(void);
    void Send(Mail pMail);
	void Receive();
    void Register();
    void Announce(std::string pAnnouncement);
    void AddSubscriber(std::string pSubscriber);
    std::vector<std::string> GetSubscribers();
private:
    MessagingManager* messagingManager;
    std::vector<Mail> inMail;
    std::string messengerID;
    std::vector<std::string> subscribers;
};

#endif