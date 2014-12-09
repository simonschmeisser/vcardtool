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

                //std::cout << line << std::endl;
                std::istringstream iline(line);

                std::getline(iline, tag, ':');

                std::string param;
                int s = tag.find(';');
                if (s != tag.npos) {
                    param = tag.substr(s+1);
                    tag.resize(s);
                }

                //std::cout << "tag: " << tag << " param: " << param << std::endl;

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
                    std::string address;
                    email mail;
                    std::getline(iline, address);
                    if (!address.empty()) {
                        mail.setAddress(address);
                        mail.setCategory(param);
                        new_contact.addEmail(mail);
                    }

                } else if (tag == "TEL") {
                    std::string number;
                    phone num;
                    std::getline(iline, number);
                    if (!number.empty()) {
                        num.setNumber(number);
                        num.setCategory(param);
                        new_contact.addPhone(num);
                    }
                } else if (tag == "NOTE") {
                    std::string note;
                    std::getline(iline, note);
                    new_contact.addNotes(note);

                } else if (tag == "ADR") {

                } else if (tag == "PHOTO") {
                    //need to prepend the data that is in line
                    std::string data;
                    std::getline(iline, data);
//                    std::cout << "Parsing PHOTO: first chunk: " << data << std::endl;
                    //need to search for "=" as the end of data
                    std::string next_data;
                    while ( std::getline(vcardfile, next_data) && !next_data.empty() && next_data.at(0) != (char)13) {
                        data +=  next_data;
//                        std::cout << "Next line: " << next_data << std::endl;
//                        std::cout << "length: " << next_data.length() << std::endl;
//                        if (next_data.length() > 0)
//                            std::cout << (int)next_data.c_str()[0] << " ";
//                        if (next_data.length() > 1)
//                            std::cout << (int)next_data.c_str()[1];
//                        std::cout << std::endl;
//                        std::cout << "New data: " << data << std::endl;

                    }
//                    std::cout << "data: " << std::endl << data << std::endl;
//                    std::cout << "length of data: " << data.length() << std::endl;
                } else if (tag == "VERSION") {
                    std::string ver;
                    std::getline(iline, ver);
                    if (ver != "2.1")
                        std::cerr << "Currently only version 2.1 is \"tested\", you might loose even more data since this is " << ver << std::endl;
                } else if (tag == "BEGIN") {
                    //all fine, nothing to do
                } else {
                    std::cout << "Unhandled tag:" << tag << " param: " << param << std::endl;
                }
            }
            contacts.push_back(new_contact);
        }
        //else std::cout << line << std::endl;
    }
    return contacts;
}
