#include "Stack.hpp"

// Конструктор
Stack::Stack() {
    capacity = 10;
    data = new int[capacity];
    size = 0; 
}

// Конструктор копирования
Stack::Stack(const Stack& other) {
    capacity = other.capacity;
    size = other.size;
    data = new int[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}


Stack::~Stack() {
    delete[] data;
}

// Присваивание
Stack& Stack::operator=(const Stack& other) {
    if (this == &other) return *this;
    delete[] data;
    
    capacity = other.capacity;
    size = other.size;
    data = new int[capacity];
    
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
    
    return *this;
}

void Stack::push(int value) {
    // Если массив полон
    if (size >= capacity) {
        int newCapacity = capacity * 2;
        int* newData = new int[newCapacity];
        
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
    
    data[size] = value;  // Добавляем в конец
    size++;               // Увеличиваем размер
}


int Stack::pop() {
    if (size == 0) return -1; 
    
    size--;
    return data[size];
}


int Stack::top() const {
    if (size == 0) return -1;
    return data[size - 1];
}

bool Stack::isEmpty() const {
    return size == 0;
}

int Stack::getSize() const {
    return size;
}

void Stack::clear() {
    size = 0;
}

// Сравнение
bool Stack::operator==(const Stack& other) const {
    if (size != other.size) return false;
    
    for (int i = 0; i < size; i++) {
        if (data[i] != other.data[i]) return false;
    }
    
    return true;
}

std::ostream& operator<<(std::ostream& os, const Stack& stack) {
    os << "[";
    for (int i = 0; i < stack.size; i++) {
        os << stack.data[i];
        if (i < stack.size - 1) os << ", ";
    }
    os << "]";
    return os;
}