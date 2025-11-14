#include <iostream>
int main() {

unsigned char  A;
    std::cin >> A;
    
    if (((A - '0') > 0) && ((A - '0') < 10)) {
        std::cout << (A-'0') * (A-'0') * (A-'0') << std::endl;
    }

    else {
        std::cout << 0 << std::endl;
     
    }
    return 0;

}