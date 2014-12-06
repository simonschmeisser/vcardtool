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
                        new_contact.last_name = last_name;

                    std::string first_name;
                    std::getline(iline, first_name, ';');
                    if (!first_name.empty())
                        new_contact.first_name = first_name;

                    std::string middle_name;
                    std::getline(iline, middle_name, ';');
                    if (!middle_name.empty())
                        new_contact.middle_name = middle_name;

                    std::string title;
                    std::getline(iline, title, ';');
                    if (!title.empty())
                        new_contact.title = title;


                }
            }
            contacts.push_back(new_contact);
        }
        //else std::cout << line << std::endl;
    }
    return contacts;
}
