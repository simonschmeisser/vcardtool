#include "phone.h"

phone::phone()
{
}
std::string phone::number() const
{
    return m_number;
}

void phone::setNumber(const std::string &number)
{
    m_number = number;
}
std::string phone::category() const
{
    return m_category;
}

void phone::setCategory(const std::string &category)
{
    m_category = category;
}


