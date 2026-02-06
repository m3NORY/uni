#include <iostream>
#include <vector>
#include <fstream>
#include "statistics.h"

int main() {
    setlocale(LC_ALL, "Russian"); 
    std::vector<double> numbers;
    std::cout << "Введите числа через пробел: ";
    
    double num;
    while (std::cin >> num) {
        numbers.push_back(num);
    }
    std::cin.clear(); // Очищаем ошибку ввода
    
    if (numbers.empty()) {
        std::cout << "Вы не ввели числа" << std::endl;
        return 0;
    }
    
    double avg = Stats::average(numbers);
    double med = Stats::middle(numbers);
    double var = Stats::spread(numbers);
    double min = Stats::smallest(numbers);
    double max = Stats::largest(numbers);
    double diff = max - min; // Размах
    
    std::cout << "Количество: " << numbers.size() << std::endl;
    std::cout << "Среднее: " << avg << std::endl;
    std::cout << "Медиана: " << med << std::endl;
    std::cout << "Дисперсия: " << var << std::endl;
    std::cout << "Мин: " << min << std::endl;
    std::cout << "Макс: " << max << std::endl;
    std::cout << "Размах: " << diff << std::endl;
    
    char save;
    std::cout << "Сохранить в файл? (y/n): ";
    std::cin >> save;
    
    if (save == 'y' || save == 'Y') {
        std::ofstream file("result.txt");
        file << "Результаты анализа:" << std::endl;
        file << "Среднее: " << avg << std::endl;
        file << "Медиана: " << med << std::endl;
        file << "Дисперсия: " << var << std::endl;
        file << "Мин: " << min << std::endl;
        file << "Макс: " << max << std::endl;
        file << "Размах: " << diff << std::endl;
        file.close();
        std::cout << "Сохранено в result.txt" << std::endl;
    }
    std::cin.ignore();
    std::cin.get();
    
    return 0;
}