#ifndef EMAIL_H
#define EMAIL_H

#include <string>

class email
{
public:
    email();
    std::string getAddress() const;
    void setAddress(const std::string &value);

    std::string getCategory() const;
    void setCategory(const std::string &value);

private:
    std::string m_address;
    std::string m_category;
};

#endif // EMAIL_H
