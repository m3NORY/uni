#include "ordersss.hpp"
#include <fstream>
#include <iostream>

int main() {
    Order* head = nullptr;
    
    std::ifstream input("input.txt");
    if (!input) {
        std::cout << "Ошибка открытия файла!";
        return 1;
    }
    
    int count;
    input >> count;
    
    for (int i = 0; i < count; i++) {
        int num;
        char name[100];
        float sum;
        char status[100];
        
        input >> num >> name >> sum >> status;
        addOrder(head, num, name, sum, status);
    }
    input.close();
    
    printToFile(head, "output.txt");
    
    std::ofstream output("output.txt", std::ios::app);
    Order* maxOrder = findMaxSum(head);
    if (maxOrder != nullptr) {
        output << "Заказ с максимальной суммой: №" << maxOrder->number 
               << " (" << maxOrder->name << ", " << maxOrder->sum << ")";
    }
    
    float total = totalSum(head);
    output << "Общая сумма всех заказов: " << total ;
    output.close();
    
    clearList(head);

    return 0;
}