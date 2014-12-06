#include "vcardreader.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

std::vector<contact> VCardReader::readFromFile(const std::string &filename)
{
    std::vector<contact> contacts;

    std::ifstream vcardfile(filename);

    std::string line;
    std::string tag;

    while (std::getline(vcardfile, line)) {
        if (!line.compare(0, 11, "BEGIN:VCARD")) {
            std::cout << "next VCARD" << std::endl;
            contact new_contact;
            for (;vcardfile.good() && line.compare(0, 9, "END:VCARD");  std::getline(vcardfile, line)) {

                std::cout << line << std::endl;
                std::istringstream iline(line);

                std::getline(iline, tag, ':');

                std::cout << "tag: " << tag << std::endl;

                if (tag == "N") {
                        std::string last_name;
                        std::getline(iline, last_name, ';');
                        if (!last_name.empty())
                            new_contact.setLastName(last_name);

                        std::string first_name;
                        std::getline(iline, first_name, ';');
                        if (!first_name.empty())
                            new_contact.setFirstName(first_name);

                        std::string middle_name;
                        std::getline(iline, middle_name, ';');
                        if (!middle_name.empty())
                            new_contact.setMiddleName(middle_name);

                        std::string title;
                        std::getline(iline, title, ';');
                        if (!title.empty())
                            new_contact.setTitle(title);

                } else if (tag == "FN") {
                    std::string formatted_name;
                    std::getline(iline, formatted_name);
                    if (!formatted_name.empty())
                        new_contact.setFormattedName(formatted_name);

                } else if (tag == "EMAIL") {
                    std::string category;
                    std::string address;
                    email mail;
                    std::getline(iline, address);
                    if (!address.empty())
                        mail.setAddress(address);
                    new_contact.addEmail(mail);

                } else if (tag == "EMAIL;HOME") {
                    std::string address;
                    email mail;
                    mail.setCategory("HOME");
                    std::getline(iline, address);
                    if (!address.empty())
                        mail.setAddress(address);
                    new_contact.addEmail(mail);

                } else if (tag == "EMAIL;WORK") {
                    std::string address;
                    email mail;
                    mail.setCategory("WORK");
                    std::getline(iline, address);
                    if (!address.empty())
                        mail.setAddress(address);
                    new_contact.addEmail(mail);

                } else if (tag == "TEL") {

                } else if (tag == "NOTE") {

                } else {
                    std::cout << "Unhandled tag:" << tag << std::endl;
                }
            }
            contacts.push_back(new_contact);
        }
        //else std::cout << line << std::endl;
    }
    return contacts;
}
