#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <vector>

#include "address.h"
#include "email.h"
#include "phone.h"

class contact {
public:


    std::string getLastName() const;
    void setLastName(const std::string &value);
    std::string getMiddleName() const;
    void setMiddleName(const std::string &value);
    std::string getFirstName() const;
    void setFirstName(const std::string &value);
    std::string getTitle() const;
    void setTitle(const std::string &value);
    std::string getFormattedName() const;
    void setFormattedName(const std::string &value);
    std::vector<phone> getPhones() const;
    void addPhone(const phone &value);
    std::vector<email> getEmails() const;
    void addEmail(const email &value);

    std::vector<std::string> getNotes() const;
    void addNotes(const std::string &value);

    std::vector<address> getAddresses() const;
    void addAddress(const address &value);

private:
    std::string lastName;
    std::string middleName;
    std::string firstName;
    std::string title;

    std::string formattedName;

    std::vector<phone> phones;
    std::vector<email> emails;

    std::vector<address> addresses;

    std::vector<std::string> notes;
};

#endif
