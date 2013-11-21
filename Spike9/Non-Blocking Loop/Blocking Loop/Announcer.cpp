#include "Announcer.h"


Announcer::Announcer(MessagingManager* pMessagingManager){
    messagingManager = pMessagingManager;
    messengerID = "Announcer";
    Register();
}


Announcer::~Announcer(void)
{
}

void Announcer::Send(Mail pMail) {
    messagingManager->Add(pMail);
}
void Announcer::Receive() {
    inMail = messagingManager->MailForID(messengerID);
}

void Announcer::Register() {
    messagingManager->RegisterID(messengerID);
}

void Announcer::AddSubscriber(std::string pSubscriber) {
    subscribers.insert(subscribers.end(), pSubscriber);
}

std::vector<std::string> Announcer::GetSubscribers() {
    return subscribers;
}

void Announcer::Announce(std::string pAnnouncement) {
    Mail* mail;
    for(std::vector<int>::size_type i = 0; i != subscribers.size(); i++) {
        mail = new Mail(messengerID,subscribers[i],pAnnouncement + "\n");
        Send(*mail);
    }
    delete mail;
}