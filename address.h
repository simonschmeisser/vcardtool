#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

class address
{
public:
    address();
    std::string category() const;
    void setCategory(const std::string &category);

    std::string postAddress() const;
    void setPostAddress(const std::string &postAddress);

private:
    std::string m_category;
    std::string m_postAddress;

};

#endif // ADDRESS_H
