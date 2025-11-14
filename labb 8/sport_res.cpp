#include "sport_res.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>

Runner* readRunnersFromFile(const std::string& filename, int& count) {
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        std::cout << "Нельзя открыть файл" << filename << std::endl;
        return nullptr;
    }
    
    file >> count;
    if (count <= 0 || count > 30) {
        std::cout << "Некорректное количество участников: " << count << std::endl;
        return nullptr;
    }
    
    Runner* runners = new Runner[count];
    
    for (int i = 0; i < count; i++) {
        file >> runners[i].name >> runners[i].time;
        
        if (runners[i].time <= 0) {
            std::cout << "Некорректное время у участника" << runners[i].name << std::endl;
            delete[] runners;
            return nullptr;
        }
    }
    
    file.close();
    std::cout << "Прочитано " << count << " участников" << std::endl;
    return runners;
}


void sortRunnersByTime(Runner* runners, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (runners[j].time > runners[j + 1].time) {
                Runner temp = runners[j];
                runners[j] = runners[j + 1];
                runners[j + 1] = temp;
            }
        }
    }
    std::cout << "Участники отсортированы по времени" << std::endl;
}

Runner findWinner(Runner* runners, int count) {
    Runner winner = runners[0];
    
    for (int i = 1; i < count; i++) {
        if (runners[i].time < winner.time) {
            winner = runners[i];
        }
    }
    
    std::cout << "Победитель: " << winner.name << " с временем " << winner.time << " сек" << std::endl;
    return winner;
}

float calculateAVGTime(Runner* runners, int count) {
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += runners[i].time;
    }
    float average = sum / count;
    std::cout << "Среднее время: " << average << " сек" << std::endl;
    return average;
}

void writeResultsToFile(const std::string& filename, Runner* runners, int count) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Нельзя создать файл" << filename << std::endl;
        return;
    }
    Runner winner = findWinner(runners, count);
    float average = calculateAVGTime(runners, count);
    
    file << "Победитель: " << winner.name << " (" << winner.time << " .сек)" << std::endl;
    file << "Среднее время: " << average << " .сек" << std::endl << std::endl;
    
    file << "Итоговая таблица:" << std::endl;
    for (int i = 0; i < count; i++) {
        file << (i + 1) << ". " << runners[i].name << ": " << runners[i].time << " сек" << std::endl;
    }
    
    file.close();
    std::cout << "Результаты записаны в файл " << filename << std::endl;
}