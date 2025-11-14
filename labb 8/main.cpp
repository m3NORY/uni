#include <iostream>
#include "sport_res.hpp"

int main() {
    const std::string inputFile = "input.txt";
    const std::string outputFile = "output.txt";
    int runnerCount = 0;
    
    Runner* runners = readRunnersFromFile(inputFile, runnerCount);
    
    if (runners == nullptr) {
        std::cout << "Ошибка" << std::endl;
        return 1;
    }
    
    sortRunnersByTime(runners, runnerCount);
    writeResultsToFile(outputFile, runners, runnerCount);
    
    delete[] runners;
    
    std::cout << "Все!" << std::endl;
    return 0;
}
// всем пока