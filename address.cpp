#include "address.h"

address::address()
{
}
std::string address::category() const
{
    return m_category;
}

void address::setCategory(const std::string &category)
{
    m_category = category;
}
std::string address::postAddress() const
{
    return m_postAddress;
}

void address::setPostAddress(const std::string &postAddress)
{
    m_postAddress = postAddress;
}


