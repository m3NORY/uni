#include "perevod.hpp"
#include <iostream>
#include <algorithm>

namespace perevod {
    std::string convertRecursive(int number, int b) {
        // Базовый случай рекурсии
        if (number == 0) {
            return "";
        }

        int remainder = number % b;
        
        char digit;
        if (remainder < 10) {
            digit = '0' + remainder; // '0' -> '9'
        } else {
            digit = 'A' + (remainder - 10); // 'A' -> 'F'
        }
        std::string result = convertRecursive(number / b, b);
        result += digit;
        return result;
    }
    
    std::string toBinary(int number) {
        if (number == 0) {
            return "0"; 
        }
        return convertRecursive(number, 2);
    }
    
    std::string toOctal(int number) {
        if (number == 0) {
            return "0";
        }
        return convertRecursive(number, 8);
    }
    
    std::string toHex(int number) {
        if (number == 0) {
            return "0";
        }
        return convertRecursive(number, 16);
    }
    
    void showProcess(int number, int b, const std::string& systemName) {
        std::cout << "Процесс перевода в " << systemName << " систему:";
        int n = number;
        while (n > 0) {
            std::cout << n << " / " << b << " = " << (n / b) << ", остаток " << (n % b);
            if (b == 16) {
                int h = n % b;
                if (h >= 10) {
                    std::cout << " (" << char('A' + (h - 10)) << ")";
                }
            }
            std::cout << std::endl;
            
            n = n / b;
        }
        std::cout << std::endl;
    }
}