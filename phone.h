#ifndef PHONE_H
#define PHONE_H

#include <string>

class phone
{
public:
    phone();
    std::string number() const;
    void setNumber(const std::string &number);

    std::string category() const;
    void setCategory(const std::string &category);

private:
    std::string m_number;
    std::string m_category;
};

#endif // PHONE_H
