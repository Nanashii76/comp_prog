#include <iostream>
#include <bitset>

int getIthBit(int n, int i) {

    int mask = (1<<i);
    return (mask&n) > 0 ? 1 : 0;

}


int main(void) {

    int n, i;
    std::cin >> n >> i;

    std::cout << "Number(decimal): " << n << std::endl;
    std::cout << "Number(binary): " << std::bitset<8>(n) << std::endl;
    std::cout << "Bit at " << i << " position: " << getIthBit(n,i) << std::endl;


}