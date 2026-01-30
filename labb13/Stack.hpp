#ifndef STACK_H
#define STACK_H

#include <iostream>

class Stack {
private:
    int* data; 
    int capacity;  
    int size;       

public:
    Stack();
    Stack(const Stack& other);
    ~Stack();
    
    Stack& operator=(const Stack& other);
    
    bool operator==(const Stack& other) const;
    
    void push(int value);
    int pop();
    int top() const;
    bool isEmpty() const;
    int getSize() const;
    void clear();

friend std::ostream& operator<<(std::ostream& os, const Stack& stack);

};

#endif