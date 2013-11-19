#ifndef MESSENGER
#define MESSENGER

#include "Mail.h"
#include <queue>

class Messenger {
public:
    virtual void Receive(std::vector<Mail*> pMail) = 0;
    virtual void Send(Mail* pMail) = 0;

private:
	std::vector<Mail*> inbound;
};

#endif