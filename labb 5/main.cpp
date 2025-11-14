#include <iostream>
#include "math_functions.h"



int main() {
    setlocale(LC_ALL, "Russian");
    int numbers[100];
    int count;
    
    Math::inputNumbers(numbers, count);
    
    if (count == 0) {
        std::cout << "Ошибка: не введено ни одного числа!" << std::endl;
        return 1;
    }

    int currentGCD = numbers[0];
    int currentLCM = numbers[0];

    for (int i = 1; i < count; i++) {
        currentGCD = Math::findGCD(currentGCD, numbers[i]);
        currentLCM = Math::findLCM(currentLCM, numbers[i]);
    }
    
    Math::printResults(currentGCD, currentLCM);
    
    return 0;
}