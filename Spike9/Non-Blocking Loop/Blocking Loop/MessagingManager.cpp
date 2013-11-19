#include "MessagingManager.h"
#include <iostream>

MessagingManager::MessagingManager(void)
{
}

MessagingManager::~MessagingManager(void)
{
}

void MessagingManager::RegisterID(std::string id) {
    for(std::vector<int>::size_type i = 0; i != messengerIDs.size(); i++) {
        if(messengerIDs[i].compare(id) == 0) {
            std::cout << "\nID already registered. Exiting registration now.\n";
            return;
        }
    }

    std::cout << "\nID not registered. Registering now.\n";
    messengerIDs.push_back(id);
}

void MessagingManager::Add(Mail pMail) {
    outMail.push_back(pMail);
}

std::vector<Mail> MessagingManager::MailForID(std::string id) {
    std::vector<Mail> mailForID;
    std::vector<Mail> newOutMail;

    if(outMail.empty()) {
        return mailForID;
    }
    else {
        for(std::vector<int>::size_type i = 0; i != outMail.size(); i++) {
            if(outMail[i].GetReceiver().compare(id) == 0) {
                std::cout << "\nMail for " + id + " adding now\n";
                mailForID.push_back(outMail[i]);
            }
            else {
                newOutMail.push_back(outMail[i]);
            }
        }
        outMail = newOutMail;
        return mailForID;
    }
}