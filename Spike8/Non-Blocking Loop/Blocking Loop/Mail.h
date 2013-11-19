#ifndef MAIL_H
#define MAIL_H

#include <string>

class Mail
{
public:
    Mail(std::string pSender, std::string pReceiver, std::string contents);
    Mail();
    ~Mail(void);
    inline std::string GetReceiver() { return receiver; }
    inline std::string GetContents() { return contents; }

private:
    std::string sender;
    std::string contents;
    std::string receiver;
};

#endif