#include <iostream>
#include "fraction.h"

using namespace Fractions;

int main() {
    setlocale(LC_ALL, "rus");
    std::cout << "Демонстрация указателей и динамической памяти" << std::endl;
    
    std::cout << "1. СОЗДАЕМ ДРОБИ:" << std::endl;
    
    Fraction* frac1 = createFraction(3, 4);  // 3/4
    Fraction* frac2 = createFraction(2, 6);  // 2/6
    Fraction* frac3 = createFraction(5, 10); // 5/10
    
    std::cout << "Дробь 1: "; printFraction(frac1); std::cout << std::endl;
    std::cout << "Дробь 2: "; printFraction(frac2); std::cout << std::endl;
    std::cout << "Дробь 3: "; printFraction(frac3); std::cout << std::endl;
    

    std::cout << "2. СОКРАЩАЕМ ДРОБИ:" << std::endl;
    
    std::cout << "До сокращения: "; printFraction(frac2); 
    simplifyFraction(frac2);
    std::cout << " -> "; printFraction(frac2); std::cout << std::endl;
    
    std::cout << "До сокращения: "; printFraction(frac3);
    simplifyFraction(frac3);
    std::cout << " -> "; printFraction(frac3); std::cout << std::endl;
    
    
    std::cout << "3. СЛОЖЕНИЕ ДРОБЕЙ:" << std::endl;
    
    Fraction* sum = addFractions(frac1, frac2);
    std::cout << "Сумма: "; 
        printFraction(frac1); 
    std::cout << " + "; 
        printFraction(frac2);
    std::cout << " = "; 
        printFraction(sum);
    std::cout << std::endl;
    
    
    std::cout << "4. СРАВНЕНИЕ ДРОБЕЙ:" << std::endl;
    
    int result = compareFractions(frac1, frac2);
    std::cout << "Сравнение: "; 
    printFraction(frac1);
    std::cout << " <=> "; 
    printFraction(frac2);
    std::cout << " = ";
    
    if (result == -1) {
        std::cout << "первая меньше"; }
    else if (result == 1) {
        std::cout << "первая больше"; }
    else {
        std::cout << "дроби равны"; }
    
    
    
    std::cout << "5. ПРОВЕРКА ОШИБОК:" << std::endl;
    
    
    Fraction* badFraction = createFraction(1, 0);
    if (badFraction == nullptr) {
        std::cout << "Нельзя делить на ноль!" << std::endl;
    }
    
    
    std::cout << "6. ОСВОБОЖДЕНИЕ ПАМЯТИ:" << std::endl;
    
    
    deleteFraction(frac1);
    deleteFraction(frac2);
    deleteFraction(frac3);
    deleteFraction(sum);
    
    
    std::cout << " ВСЯ ПАМЯТЬ ОСВОБОЖДЕНА! ПРОГРАММА ЗАВЕРШЕНА. " << std::endl;
    
    return 0;
}