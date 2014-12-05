#ifndef VCARDREADER_H
#define VCARDREADER_H

#include <vector>
#include <string>

#include "contact.h"

class VCardReader {
public:
    static std::vector<contact> readFromFile(const std::string &filename);
};

#endif
