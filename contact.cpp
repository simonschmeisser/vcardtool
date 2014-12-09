#include "contact.h"


std::string contact::getMiddleName() const
{
    return middleName;
}

void contact::setMiddleName(const std::string &value)
{
    middleName = value;
}

std::string contact::getFirstName() const
{
    return firstName;
}

void contact::setFirstName(const std::string &value)
{
    firstName = value;
}

std::string contact::getTitle() const
{
    return title;
}

void contact::setTitle(const std::string &value)
{
    title = value;
}

std::string contact::getFormattedName() const
{
    return formattedName;
}

void contact::setFormattedName(const std::string &value)
{
    formattedName = value;
}

std::vector<phone> contact::getPhones() const
{
    return phones;
}

void contact::addPhone(const phone &value)
{
    phones.push_back(value);
}

std::vector<email> contact::getEmails() const
{
    return emails;
}

void contact::addEmail(const email &value)
{
    emails.push_back(value);
}
std::vector<std::string> contact::getNotes() const
{
    return notes;
}

void contact::addNotes(const std::string &value)
{
    notes.push_back(value);
}
std::vector<address> contact::getAddresses() const
{
    return addresses;
}

void contact::addAddress(const address &value)
{
    addresses.push_back(value);
}



std::string contact::getLastName() const
{
    return lastName;
}

void contact::setLastName(const std::string &value)
{
    lastName = value;
}
