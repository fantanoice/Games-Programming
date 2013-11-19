#include "Mail.h"

Mail::Mail(std::string* pSender, std::queue<std::string*>* pReceivers, std::queue<std::string*>* pContents) {
	sender = pSender;
	receivers = pReceivers;
	contents = pContents;
}

Mail::Mail(std::string* pSender, std::queue<std::string*>* pReceivers, std::string* pContent) {
    std::queue<std::string*>* contents;
    contents->push(pContent);
    Mail(pSender,pReceivers,contents);
}

Mail::Mail(std::string* pSender, std::string* pReceiver, std::queue<std::string*>* pContents) {
    std::queue<std::string*>* receivers;
    receivers->push(pReceiver);
    Mail(pSender,receivers,pContents);
}

Mail::Mail(std::string* pSender, std::string* pReceiver, std::string* pContent) {
    std::queue<std::string*>* receivers;
    receivers->push(pReceiver);
    std::queue<std::string*>* contents;
    contents->push(pContent);
    Mail(pSender,receivers,contents);
}

const std::queue<std::string*>* Mail::GetReceivers() {
    return receivers;
}

const std::queue<std::string*>* Mail::GetContents() {
    return contents;
}

const std::string* Mail::GetSender() {
    return sender;
}

Mail::Mail(void) {}
Mail::~Mail(void) {}
