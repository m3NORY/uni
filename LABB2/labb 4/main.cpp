#include <iostream>

int main() {
    int A, B;
    std::cout << "Введите два целых числа A и B (от 1 до 100000000): ";
    std::cin >> A >> B;

    if (!std::cin || A < 1 || B < 1 || A > 100000000 || B > 100000000) {
        std::cout << "Ошибка: введите целые числа от 1 до 100000000." << std::endl;
        return 0;
    }
    int a = A, b = B;
    while (b != 0) {
        int l = b;
        b = a % b;
        a = l;
    }
    int nod = a; 
    int count = 0;
    for (int i = 1; i <= nod; i++) {
        if (nod % i == 0) {
            count++; }
    }
    if (count > 50) {
        std::cout << "Общих делителей больше 50." << std::endl;
        std::cout << "Наибольший общий делитель (НОД): " << nod << std::endl;
    } 
    else {
        std::cout << "Общие делители чисел " << A << " и " << B << ": ";
        for (int i = 1; i <= nod; i++) {
            if (nod % i == 0) 
            std::cout << i << " ";
        }
        std::cout << "" << std::endl;
    }

    return 0;
}