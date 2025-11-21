#include "numbers.hpp"
#include <string>
#include <map>
#include <vector>

namespace Roman {
    std::vector<std::pair<int, std::string>> romanTable = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
        {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
        {1, "I"}
    };
    std::map<char, int> charToValue = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };
    std::string arabicToRoman(int number) {
        if (number < 1 || number > 3999) {
            return "Число должно быть от 1 до 3999";
        }
        std::string result = "";
        for (auto& pair : romanTable) {
            while (number >= pair.first) {
                result += pair.second;
                number -= pair.first;
            }
        }
        return result;
    }
    int romanToArabic(const std::string& roman) {
        if (roman.empty()) return 0;
        
        int result = 0;
        int prevValue = 0;
        for (int i = roman.length() - 1; i >= 0; i--) {
            char c = roman[i];
            if (charToValue.find(c) == charToValue.end()) {
                return -1;
            }
            int currentValue = charToValue[c];
            if (currentValue < prevValue) {
                result -= currentValue;
            } else {
                result += currentValue;
            }
            
            prevValue = currentValue;
        }
        
        return result;
    }

    bool isValidRoman(const std::string& roman) {
        if (roman.empty()) return false;
        for (char c : roman) {
            if (charToValue.find(c) == charToValue.end()) {
                return false; 
            }
        }
        
        int arabic = romanToArabic(roman);
        if (arabic <= 0) return false;
        std::string backToRoman = arabicToRoman(arabic);
        return backToRoman == roman;
    }

    std::string addRomans(const std::string& a, const std::string& b) {
        if (!isValidRoman(a) || !isValidRoman(b)) {
            return "Некорректное римское число";
        }
        
        int num1 = romanToArabic(a);
        int num2 = romanToArabic(b);
        int sum = num1 + num2;
        
        if (sum > 3999) {
            return "Сумма превышает 3999";
        }
        
        return arabicToRoman(sum);
    }

    // 5. Найти наибольшее римское число
    std::string findLargest(const std::string romans[], int count) {
        if (count <= 0) return "ERROR: Пустой массив";
        
        std::string largest = romans[0];
        int maxValue = romanToArabic(romans[0]);
        
        for (int i = 1; i < count; i++) {
            int currentValue = romanToArabic(romans[i]);
            if (currentValue > maxValue) {
                maxValue = currentValue;
                largest = romans[i];
            }
        }
        
        return largest;
    }
}