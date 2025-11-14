#ifndef FRACTION_H
#define FRACTION_H


struct Fraction {
    int numerator;   // числитель 
    int denominator; // знаменатель 
};


namespace Fractions {


Fraction* createFraction(int num, int den);


void deleteFraction(Fraction* frac);


void simplifyFraction(Fraction* frac);


Fraction* addFractions(const Fraction* a, const Fraction* b);


// возвращает: -1 (первая меньше), 0 (равны), 1 (первая больше)
int compareFractions(const Fraction* a, const Fraction* b);


void printFraction(const Fraction* frac);

}

#endif