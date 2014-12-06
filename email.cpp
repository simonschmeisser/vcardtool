#include "email.h"

email::email()
{
}
std::string email::getAddress() const
{
    return m_address;
}

void email::setAddress(const std::string &value)
{
    m_address = value;
}
std::string email::getCategory() const
{
    return m_category;
}

void email::setCategory(const std::string &value)
{
    m_category = value;
}


