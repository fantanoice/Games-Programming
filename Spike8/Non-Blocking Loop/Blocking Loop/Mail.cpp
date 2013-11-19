#include "Mail.h"


Mail::Mail(std::string pSender, std::string pReceiver, std::string pContents)
{
    sender = pSender;
    contents = pContents;
    receiver = pReceiver;
}

Mail::Mail(void)
{
}

Mail::~Mail(void)
{
}
