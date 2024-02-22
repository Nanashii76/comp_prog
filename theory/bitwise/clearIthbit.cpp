#include <iostream>
#include <bitset>

void clearIthbit(int &bin, int i) {

    int mask = 1;
    mask = (mask << i);

    bin &= ~(mask);

}

int main(){

    int n, i;
    std::cin >> n >> i;
    clearIthbit(n,i);

    std::cout <<"dec: " << n << " bin: " <<std::bitset<8>(n) << std::endl;

}