#include <iostream>
#include <bitset>


int clearLastBits(int &n, int i) {

    int mask = (-1<<i); // -1 is equal to all numbers set to 1
    return (n&mask);

}

int main(void) {
    
    int n, i;
    std::cin >> n >> i;

    std::cout << "Number(decimal) : " << n << std::endl;
    std::cout << "Number(binary) : " << std::bitset<4>(n) << std::endl;
    std::cout << "pposotion to change : " << i << std::endl;
    std::cout << "newNumber(binary) : " << std::bitset<4>(clearLastBits(n,i)) << std::endl;
    std::cout << "newNumber(decimal) : " << clearLastBits(n,i) << std::endl;

}





