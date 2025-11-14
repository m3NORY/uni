#include <iostream>
#include "operations.hpp"


int main() {
    using namespace NumberArrayOps;

    std::cout << "=== Number Array Operations Demo ===" << std::endl;

   
    NumberArray* numbers = createArray(6);
    if (numbers == nullptr) {
        std::cout << "Failed to create array!" << std::endl;
        return 1;
    }

    
    numbers->data[0] = 2.5f;
    numbers->data[1] = -3.0f;
    numbers->data[2] = 4.0f;
    numbers->data[3] = -1.5f;
    numbers->data[4] = 6.0f;
    numbers->data[5] = -2.0f;

    std::cout << "\n1. Original array:" << std::endl;
    printArray(numbers);

    
    applyOperation(numbers, square);
    std::cout << "\n2. After squaring:" << std::endl;
    printArray(numbers);

    
    filterArray(numbers, isPositive);
    std::cout << "\n3. After filtering positive numbers:" << std::endl;
    printArray(numbers);

    
    float sum = reduceArray(numbers, add, 0.0f);
    std::cout << "\n4. Sum of array: " << sum << std::endl;

    
    std::cout << "\n5. Using lambda expression:" << std::endl;

    
    auto addTen = [](float x) -> float {
        return x + 10.0f;
        };

    applyOperation(numbers, addTen);
    printArray(numbers);

    
    deleteArray(numbers);

    std::cout << "\n=== Demo completed ===" << std::endl;
    return 0;
}