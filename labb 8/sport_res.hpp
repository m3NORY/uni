#pragma once

#include <string>

struct Runner {
    std::string name;
    float time;
};

Runner* readRunnersFromFile(const std::string& filename, int& count);
void sortRunnersByTime(Runner* runners, int count);
Runner findWinner(Runner* runners, int count);
float calculateAVGTime(Runner* runners, int count);  
void writeResultsToFile(const std::string& filename, Runner* runners, int count);