#ifndef MAIL
#define MAIL

#include <string>
#include <queue>

class Mail {
    public:
	    Mail(void);
	    ~Mail(void);
	    Mail(std::string* pSender, std::queue<std::string*>* pReceivers, std::queue<std::string*>* pContents);
        Mail(std::string* pSender, std::queue<std::string*>* pReceivers, std::string* pContent);
        Mail(std::string* pSender, std::string* pReceiver, std::queue<std::string*>* pContents);
        Mail(std::string* pSender, std::string* pReceiver, std::string* pContent);
        const std::queue<std::string*>* GetReceivers();
        const std::queue<std::string*>* GetContents();
        const std::string* GetSender();
    private:
	    std::queue<std::string*>* receivers;
	    std::string* sender;
	    std::queue<std::string*>* contents;
};

#endif