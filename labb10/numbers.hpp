#pragma once
#include <string>
namespace Roman {
    std::string arabicToRoman(int number);
    int romanToArabic(const std::string& roman);
    bool isValidRoman(const std::string& roman);
    std::string addRomans(const std::string& a, const std::string& b);
    std::string findLargest(const std::string romans[], int count);
}