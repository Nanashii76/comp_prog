#include <iostream>
#include <bitset>

int clearIthbit(int n, int i) {

    int mask = (1<<i);
    return (n&(~mask));

}

int main(void) {
    
    int n, i;
    std::cin >> n >> i;

    std::cout << "Number(decimal) : " << n << std::endl;
    std::cout << "Number(binary) : " << std::bitset<4>(n) << std::endl;
    std::cout << "pposotion to change : " << i << std::endl;
    std::cout << "newNumber(binary) : " << std::bitset<4>(clearIthbit(n,i)) << std::endl;
    std::cout << "newNumber(decimal) : " << clearIthbit(n,i) << std::endl;

}