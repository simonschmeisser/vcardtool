#include "vcardreader.h"

#include <fstream>
#include <iostream>
#include <string>

std::vector<contact> VCardReader::readFromFile(const std::string &filename)
{
    std::vector<contact> contacts;

    std::ifstream vcardfile(filename);

    std::string line;

    while (std::getline(vcardfile, line)) {
        if (!line.compare(0, 11, "BEGIN:VCARD")) {
            std::cout << "next VCARD" << std::endl;
            for (;vcardfile.good() && line.compare(0, 9, "END:VCARD");  std::getline(vcardfile, line)) {

                std::cout << line << std::endl;
            }
        }
        //else std::cout << line << std::endl;
    }
    return contacts;
}
