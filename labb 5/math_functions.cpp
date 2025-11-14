#include "math_functions.h"
#include <iostream>
#include <cmath>



namespace Math {


int findGCD(int a, int b) {
    a = abs(a);  
    b = abs(b);
    
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int findLCM(int a, int b) {
    
    if (a == 0 || b == 0) {
        return 0;
    }
    
    return abs(a * b) / findGCD(a, b);
}

void inputNumbers(int numbers[], int& count) {
    setlocale(LC_ALL, "Russian");
    std::cout << "Введите числа (0 для завершения ввода):" << std::endl;
    
    count = 0;
    int number;
    
    while (true) {
        std::cout << "Число " << (count + 1) << ": ";
        std::cin >> number;
        
        if (std::cin.fail()) {
            std::cout << "Ошибка! Введите целое число." << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }
        
        if (number == 0) {
            break;
        }
        
        numbers[count] = number;
        count++;
        
        if (count >= 100) {
            std::cout << "Достигнут максимум чисел (100)." << std::endl;
            break;
        }
    }
}

void printResults(int gcd, int lcm) {
    setlocale(LC_ALL, "Russian");
    std::cout << "\n=== РЕЗУЛЬТАТЫ ===" << std::endl;
    std::cout << "Наибольший общий делитель (НОД): " << gcd << std::endl;
    std::cout << "Наименьшее общее кратное (НОК): " << lcm << std::endl;
    std::cout << "===================" << std::endl;
}

}