#include "Announcer.h"


Announcer::Announcer(void)
{
}


Announcer::~Announcer(void)
{
}

void Announcer::Send(Mail pMail) {
    game->GetMessagingManager()->Add(pMail);
}
void Announcer::Receive() {
    inMail = game->GetMessagingManager()->MailForID(messengerID);
}

void Announcer::Register() {
    game->GetMessagingManager()->RegisterID(messengerID);
}