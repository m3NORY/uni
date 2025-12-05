#pragma once
#include <string>

namespace perevod {
    std::string toBinary(int number);
    std::string toOctal(int number);
    std::string toHex(int number);
    void showProcess(int number, int base, const std::string& systemName);
}

