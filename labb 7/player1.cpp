#include "operations.hpp"
#include <iostream>  

namespace ArrayOperations {


NumberArray* createArray(int size) {
    if (size <= 0) {
        return nullptr;
    }
    // структура
    NumberArray* arr = new NumberArray;
    
    arr->data = new float[size];
    arr->size = size;
    
    // Заполняем массив нулями
    for (int i = 0; i < size; i++) {
        arr->data[i] = 0.0f;
    }
    
    return arr;
}


void deleteArray(NumberArray* arr) {
    if (arr != nullptr) {
        // Сначала удаляем массив чисел
        delete[] arr->data;
        // Затем удаляем саму структуру
        delete arr;
    }
}

void applyOperation(NumberArray* arr, float (*operation)(float)) {
    if (arr == nullptr || operation == nullptr) {
        return;
    }
    
    // Проходим по всем элементам массива
    for (int i = 0; i < arr->size; i++) {
        // Применяем операцию к текущему элементу
        arr->data[i] = operation(arr->data[i]);
    }
}


float square(float x) {
    return x * x;
}
float absolute(float x) {
    return std::abs(x);
}

}