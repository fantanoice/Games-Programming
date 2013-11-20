#ifndef ANNOUNCER_H
#define ANNOUNCER_H

#include "Messenger.h"
#include "MessagingManager.h"

class Announcer: public Messenger {
public:
    Announcer(void);
    ~Announcer(void);
    void Send(Mail pMail);
	void Receive();
    void Register();
};

#endif