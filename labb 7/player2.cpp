#include "operations.hpp"
#include <cmath>

namespace ArrayOperations {
    void filterArray(NumberArray* arr, bool (*predicate)(float)) {
        if (arr == nullptr || predicate == nullptr) {
            return;
        }
        for (int i = 0; i < arr->size; i++) {
            if (!predicate(arr->data[i])) {
                arr->data[i] = 0.0;
            }
        }
    }

    float reduceArray(const NumberArray* arr, float (*operation)(float, float), float initial) {
        if (arr == nullptr || operation == nullptr) {
            return initial;  
        }

        float result = initial;

        for (int i = 0; i < arr->size; i++) {
           
            result = operation(result, arr->data[i]);
        }
        return result;
    }
    
    bool isPositive(float x) {
        return x > 0;
    }

    bool isEven(float x) {
        return std::fmod(x, 2.0f) == 0.0f;
    }

    float add(float a, float b) {
        return a + b;
    }

    float multiply(float a, float b) {
        return a * b;
    }

}