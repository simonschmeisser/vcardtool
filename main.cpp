#include <vector>
#include <iostream>

#include "contact.h"
#include "vcardreader.h"
#include "vcardwriter.h"

int main() {
    std::cout << "VCardTool" << std::endl;

    std::vector<contact> contacts = VCardReader::readFromFile("../sendAll_unix.vcf");

    for (contact c : contacts) {
        std::cout << c.getFirstName() << " " << c.getLastName() << std::endl;
    }

    return 0;
}
