#pragma once


struct Order {
    int number;
    char* name;
    float sum;
    char* status;
    Order* next;
};

void addOrder(Order*& head, int num, const char* name, float sum, const char* status);
void removeFirst(Order*& head);
Order* findMaxSum(Order* head);
float totalSum(Order* head);
void printToFile(Order* head, const char* filename);
void clearList(Order*& head);

