#ifndef MESSENGER
#define MESSENGER

#include "Message.h"
#include <queue>

class Messenger {
public:
//	virtual void Receive(std::string* pSender, std::queue<std::string*>* pContents);
    virtual void Receive(Message* message);



    // Various Send functions to cover a number of acceptable parameters
    // With or without pSender. If sender isn't given, it will be given a default.
    // Queue or single string for receivers. Single string for just one receiver or the queue if there are more than one
    // Queue or single string for contents. Single string for just one message content or the queue if there are more than one



/*    virtual void Send(std::string* pSender, std::queue<std::string*>* pReceivers, std::queue<std::string*>* pContents);
    virtual void Send(std::queue<std::string*>* pReceivers, std::queue<std::string*>* pContents);
    virtual void Send(std::string* pSender, std::queue<std::string*>* pReceivers, std::string* pContent);
    virtual void Send(std::queue<std::string*>* pReceivers, std::string* pContent);
    virtual void Send(std::string* pSender, std::string* pReceiver, std::queue<std::string*>* pContents);
    virtual void Send(std::string* pReceiver, std::queue<std::string*>* pContents);
    virtual void Send(std::string* pSender, std::string* pReceiver, std::string* pContent);
    virtual void Send(std::string* pReceiver, std::string* pContent);
*/
    virtual void Send(Message* message);

private:
	std::queue<Message*> outbound;
	std::queue<Message*> inbound;
};

#endif