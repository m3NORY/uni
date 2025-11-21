#include "ordersss.hpp"
#include <cstring>
#include <fstream>
#include <iostream>


void addOrder(Order*& head, int num, const char* name, float sum, const char* status) {
    Order* newOrder = new Order;
    newOrder->number = num;
    newOrder->sum = sum;
    
    newOrder->name = new char[strlen(name) + 1];
    strcpy(newOrder->name, name);
    
    newOrder->status = new char[strlen(status) + 1];
    strcpy(newOrder->status, status);
    
    newOrder->next = nullptr;
    
    if (head == nullptr) {
        head = newOrder;
    } else {
        Order* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newOrder;
    }
}

void removeFirst(Order*& head) {
    if (head == nullptr) return;
    Order* temp = head;
    head = head->next;
    delete[] temp->name;
    delete[] temp->status;
    delete temp;
}


Order* findMaxSum(Order* head) {
    if (head == nullptr) {
        return nullptr;
    }
    Order* maxOrder = head;
    Order* current = head->next;
    while (current != nullptr) {
        if (current->sum > maxOrder->sum) {
            maxOrder = current;
        }
        current = current->next;
    }
    return maxOrder;
}

float totalSum(Order* head) {
    float total = 0;
    Order* current = head;
    while (current != nullptr) {
        total += current->sum;
        current = current->next;
    }
    return total;
}

void printToFile(Order* head, const char* filename) {
    std::ofstream file(filename);
    file << "Очередь заказов:";
    Order* current = head;
    while (current != nullptr) {
        file << "Заказ №" << current->number 
             << ", Клиент: " << current->name 
             << ", Сумма: " << current->sum 
             << ", Статус: " << current->status << "\n";
        current = current->next;
    }
    file.close();
}

void clearList(Order*& head) {
    while (head != nullptr) {
        removeFirst(head);
    }
}