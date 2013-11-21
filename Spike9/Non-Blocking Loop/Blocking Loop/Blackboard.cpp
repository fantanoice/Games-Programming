#include "Blackboard.h"


Blackboard::Blackboard(MessagingManager* pMessagingManager){
    messagingManager = pMessagingManager;
    messengerID = "Blackboard";
    Register();
}

Blackboard::~Blackboard(void) {}

void Blackboard::Update() {
    Receive();

    for(std::vector<int>::size_type i = 0; i != inMail.size(); i++) {
        SendListenerMail(inMail[i].GetContents());
    }
    
}

void Blackboard::Send(Mail pMail) {
    messagingManager->Add(pMail);
}
void Blackboard::Receive() {
    inMail = messagingManager->MailForID(messengerID);
}

void Blackboard::Register() {
    messagingManager->RegisterID(messengerID);
}

void Blackboard::GenerateListenerMail(std::string pContents, std::vector<std::string> pListeners) {
    Mail *mail;
    for(std::vector<int>::size_type i = 0; i != pListeners.size(); i++) {
        mail = new Mail(messengerID,pListeners[i],pContents + "\n");
        listenerMail.insert(listenerMail.begin(),*mail);
    }
    delete mail;
}

void Blackboard::SendListenerMail(std::string pListener) {
    std::vector<Mail> newListenerMail;
    for(std::vector<int>::size_type i = 0; i != listenerMail.size(); i++) {
        if(listenerMail[i].GetReceiver().compare(pListener) == 0) {
            Send(listenerMail[i]);
        }
        else
            newListenerMail.insert(newListenerMail.end(),listenerMail[i]);
    }
    listenerMail = newListenerMail;
}