#include <iostream>
int main() {
    unsigned int x;
    unsigned int i;
    int bitt;
    std::cout << "num::" << std::endl;
    std::cin >> x;
    std::cout << "i:" << std::endl;
    std::cin >> i;
    unsigned int maska = 1 << i;
    std::cout << ": " << std::endl;
    for (int h = 31; h >= 0; h--) {
        std::cout << ((x >> h) & 1);
    }
    std::cout << " " << std::endl;
    for (int h = 31; h >= 0; h--) {
            std::cout << ((i >> h) & 1);
    }
    if (x & maska) {
        bitt = 1;
    }
    else {
        bitt = 0;
    }
    std::cout << " " << std::endl;
    std::cout << "i: " << i << " in" << " " <<  x << "="<< " " << bitt << std::endl;
    std::cout << " " << std::endl;
    

    return 0;
}