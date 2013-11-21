#include "MessagingManager.h"
#include <iostream>

MessagingManager::MessagingManager(void)
{
}

MessagingManager::~MessagingManager(void)
{
}

void MessagingManager::Update() {
    Mail *mail;
    std::vector<Mail> newOutMail;

    for(std::vector<int>::size_type i = 0; i != outMail.size(); i++) {
        if(outMail[i].GetContents().length < 11) {
            newOutMail.push_back(outMail[i]);
        }
        else {
            if(outMail[i].GetContents().substr(0,11).compare("Blackboard|") != 0) {
                newOutMail.push_back(outMail[i]);
            } else {
                mail = new Mail(outMail[i].GetSender(), outMail[i].GetReceiver, outMail[i].GetContents().substr(12));
                Add(*mail);
            }
        }
    }
    outMail = newOutMail;
    delete mail;
}

void MessagingManager::RegisterID(std::string id) {
    for(std::vector<int>::size_type i = 0; i != messengerIDs.size(); i++) {
        if(messengerIDs[i].compare(id) == 0) {
            std::cout << "\nID already registered. Exiting registration now.\n";
            return;
        }
    }

    std::cout << "\n" + id + " not registered. Registering now.\n";
    messengerIDs.push_back(id);
    std::cout << "\n" + id + " successfully registered.\n";
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