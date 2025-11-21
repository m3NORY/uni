#include <iostream>
#include <fstream>
#include <string>
#include "numbers.hpp"

int main() {
    std::ifstream input_file("input.txt");
    
    if (!input_file.is_open()) {
        return 1;
    }

    std::string numbers[10];
    int count = 0;           
    
    std::string line;
    while (std::getline(input_file, line) && count < 10) {
        if (!line.empty()) {
            numbers[count] = line;
            count++;
        }
    }
    input_file.close();
/*
    std::cout << "Прочитано чисел: " << count << std::endl;
    std::cout << std::endl;
*/

    std::string results[20]; 
    int result_count = 0;

    results[result_count++] = "РЕЗУЛЬТАТЫ КОНВЕРТАЦИИ:";

    for (int i = 0; i < count; i++) {
        std::string current_number = numbers[i];
        
        results[result_count++] = "Входное число: " + current_number;

        if (std::isdigit(current_number[0])) {
            try {
                int arabic = std::stoi(current_number); 
                std::string roman = Roman::arabicToRoman(arabic);
                
                std::cout << "  -> Римское: " << roman << std::endl;
                results[result_count++] = "  Арабское -> Римское: " + roman;
            }
            catch (...) {
                std::cout << "некорректное число" << std::endl;
                results[result_count++] = "некорректное число";
            }
        }
        else {
            if (Roman::isValidRoman(current_number)) {
                int arabic = Roman::romanToArabic(current_number);
                
                std::cout << "  -> Арабское: " << arabic << std::endl;
                results[result_count++] = "  Римское -> Арабское: " + std::to_string(arabic);
            }
            else {
                std::cout << "некорректное римское число" << std::endl;
                results[result_count++] = "некорректное римское число";
            }
        }
        std::cout << std::endl;
    }

    results[result_count++] = "ДОПОЛНИТЕЛЬНЫЕ ОПЕРАЦИИ:";

    std::string sum_result = Roman::addRomans("X", "V");
    results[result_count++] = "Сложение: X + V = " + sum_result;
    std::cout << "Сложение: X + V = " << sum_result << std::endl;

    std::string roman_numbers[] = {"X", "V", "II", "L", "C"};
    std::string largest = Roman::findLargest(roman_numbers, 5);
    results[result_count++] = "Наибольшее из {X, V, II, L, C} = " + largest;
    std::cout << "Наибольшее число: " << largest << std::endl;

    std::ofstream output_file("output.txt");
    
    if (!output_file.is_open()) {
        std::cout << "нельзя создать файл output.txt" << std::endl;
        return 1;
    }

    for (int i = 0; i < result_count; i++) {
        output_file << results[i] << std::endl;
    }
    output_file.close();
    
    return 0; 
}