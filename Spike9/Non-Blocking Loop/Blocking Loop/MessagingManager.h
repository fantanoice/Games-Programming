#ifndef MESSAGINGMANAGER_H
#define MESSAGINGMANAGER_H

#include <vector>
#include "Mail.h"

class MessagingManager
{
public:
    MessagingManager(void);
    ~MessagingManager(void);
    void RegisterID(std::string key);
    void Add(Mail pMail);
    std::vector<Mail> MailForID(std::string id);

private:
    std::vector<std::string> messengerIDs;
    std::vector<Mail> outMail;
};

#endif