#include <vector>
#include <iostream>

#include "contact.h"
#include "vcardreader.h"
#include "vcardwriter.h"

int main() {
    std::cout << "VCardTool" << std::endl;

    std::vector<contact> contacts = VCardReader::readFromFile("../thunderbird_2.1.vcf");

    for (contact c : contacts) {
        std::cout << c.getFirstName() << " " << c.getLastName() << std::endl;
    }

    return 0;
}
