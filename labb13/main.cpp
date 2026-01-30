#include "Stack.hpp"
#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian"); 
    Stack s1;
    std::cout << "1. Пустой стек: " << s1 << std::endl;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    std::cout << "2. После push: " << s1 << std::endl;
    
    std::cout << "3. Методы:" << std::endl;
    std::cout << "   top(): " << s1.top() << std::endl;
    std::cout << "   size(): " << s1.getSize() << std::endl;
    std::cout << "   isEmpty(): " << (s1.isEmpty() ? "Да" : "Нет") << std::endl;
    std::cout << "4. pop(): " << s1.pop() << std::endl;
    std::cout << "   Теперь: " << s1 << std::endl;
    Stack s2 = s1;
    std::cout << "5. Копия: " << s2 << std::endl;
    Stack s3;
    s3 = s1;
    std::cout << "6. Присвоенный: " << s3 << std::endl;
    std::cout << "7. s1 == s2? " << (s1 == s2 ? "Да" : "Нет") << std::endl;
    s1.clear();
    std::cout << "8. После clear(): " << s1 << std::endl;
    return 0;
}