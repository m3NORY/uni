#include <iostream>
#include <fstream>
#include "sport_res.hpp"

void createTestInput() {
    std::ofstream file("input.txt");
    file << "4\n";
    file << "Иванов 45.3\n";
    file << "Петров 42.8\n";
    file << "Сидоров 48.1\n";
    file << "Козлов 44.5\n";
    file.close();
    std::cout << "Создан тестовый файл input.txt" << std::endl;
}

int main() {
    std::cout << "=== ЗАПУСК ПРОГРАММЫ ===" << std::endl;
    
    const std::string inputFile = "input.txt";
    const std::string outputFile = "output.txt";
    
    // Проверяем есть ли файл, если нет - создаем
    std::ifstream test(inputFile);
    if (!test.is_open()) {
        std::cout << "Файл input.txt не найден. Создаю..." << std::endl;
        createTestInput();
    } else {
        test.close();
        std::cout << "Файл input.txt найден!" << std::endl;
    }
    
    int runnerCount = 0;
    Runner* runners = readRunnersFromFile(inputFile, runnerCount);
    
    if (runners == nullptr) {
        std::cout << "Ошибка чтения файла!" << std::endl;
        return 1;
    }
    
    sortRunnersByTime(runners, runnerCount);
    writeResultsToFile(outputFile, runners, runnerCount);
    
    delete[] runners;
    
    std::cout << "=== ПРОГРАММА ЗАВЕРШЕНА ===" << std::endl;
    std::cout << "Проверь файл output.txt!" << std::endl;
    
    return 0;
}