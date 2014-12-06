#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <vector>

#include "email.h"
#include "phone.h"

class contact {
public:
    std::string last_name;
    std::string middle_name;
    std::string first_name;
    std::string title;

    std::vector<phone> phones;
    std::vector<email> emails;

};

#endif
