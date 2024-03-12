#include <iostream>

int main(void) {

    // to check if a number is even or odd, we just
    // have to see if the last bit is equa lto 0 or 1
    int n;
    std::cin >> n;

    // if last bit is equal to one, iss a odd number
    if(n&1)
        std::cout << "Odd" << std::endl;
    else
        std::cout << "Even" << std::endl;


}