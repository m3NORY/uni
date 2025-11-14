#include "fraction.h"
#include <iostream>

namespace Fractions {


Fraction* createFraction(int num, int den) {
    if (den == 0) {
        std::cout << "Знаменатель не может быть нулем" << std::endl;
        return nullptr;
    }
    
    // Выделяем память для новой дроби
    Fraction* newFraction = new Fraction;
    newFraction->numerator = num;
    newFraction->denominator = den;
    return newFraction;
}


void deleteFraction(Fraction* frac) {
    if (frac != nullptr) {
        delete frac; 
        std::cout << "Память освобождена" << std::endl;
    }
}

int findGCD(int a, int b) {
    if (b == 0) return a;
    return findGCD(b, a % b);
}

//Сокр дроби
void simplifyFraction(Fraction* frac) {
    if (frac == nullptr) {
        std::cout << "Дробь не существует!" << std::endl;
        return;
    }
    
    int gcd = findGCD(frac->numerator, frac->denominator);
    frac->numerator /= gcd;
    frac->denominator /= gcd;
    
    if (frac->denominator < 0) {
        frac->numerator = -frac->numerator;
        frac->denominator = -frac->denominator;
    }
}

// Функция 4: Сложить две дроби
Fraction* addFractions(const Fraction* a, const Fraction* b) {
    if (a == nullptr || b == nullptr) {
        std::cout << "Одна из дробей не существует!" << std::endl;
        return nullptr;
    }
    
    //a/b + c/d = (a*d + c*b)/(b*d)
    int newNum = a->numerator * b->denominator + b->numerator * a->denominator;
    int newDen = a->denominator * b->denominator;
    
    Fraction* result = createFraction(newNum, newDen);
    
    if (result != nullptr) {
        simplifyFraction(result);
    }
    
    return result;
}

int compareFractions(const Fraction* a, const Fraction* b) {
    if (a == nullptr || b == nullptr) {
        std::cout << "ОШИБКА: Нельзя сравнить nullptr!" << std::endl;
        return 0;
    }
    
    // Приводим к общему знаменателю и сравниваем числители
    long long left = (long long)a->numerator * b->denominator;
    long long right = (long long)b->numerator * a->denominator;
    
    if (left < right) return -1;
    if (left > right) return 1;
    return 0;
}


void printFraction(const Fraction* frac) {
    if (frac == nullptr) {
        std::cout << "NULL";
        return;
    }
    
    if (frac->denominator == 1) {
        std::cout << frac->numerator; 
    } else {
        std::cout << frac->numerator << "/" << frac->denominator;
    }
}

}