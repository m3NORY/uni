#include <iostream>
#include "perevod.hpp"

int main() {
    int number;
    char choice;
    
    do {
        std::cout << "Введите число:";
        std::cin >> number;
        
        if (std::cin.fail() || number < 0) {
            std::cout << "Ошибка";
            std::cin.clear();
            std::cin.ignore(1000, '\n'); // Очищаем буфер
            continue;
        }
        
        if (number == 0) {
            std::cout << "0 в десятичной системе = 0 в любой системе";
        } 
        else {
            perevod::showProcess(number, 2, "двоичную");
            
            std::cout << number << " в десятичной системе = " << perevod::toBinary(number) << " в двоичной";
            std::cout << number << " в десятичной системе = " << perevod::toOctal(number) << " в восьмеричной";
            std::cout << number << " в десятичной системе = " << perevod::toHex(number) << " в шестнадцатеричной";
        }
        
        std::cout << "Хотите ввести еще число? (1/0): ";
        std::cin >> choice;
        
    } 
    while (choice == 'y' || choice == 'Y');
    return 0;
}