#ifndef MESSENGER_H
#define MESSENGER_H

#include "Mail.h"
#include <vector>

class Messenger {
public:
    virtual void Receive() = 0;
    virtual void Send(Mail pMail) = 0;
    virtual void Register() = 0;

private:
	std::vector<Mail> inMail;
    std::string messengerID;
};

#endif