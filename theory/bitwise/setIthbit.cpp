#include <iostream>
#include <bitset>

void setIthbit(int &bin, int i) {

    int mask = 1;
    mask = (mask << i);

    bin |= (mask);

}


int main(void) {

    int n, i;
    std::cin >> n >> i;
    setIthbit(n,i);

    std::cout <<"dec: " << n << " bin: " <<std::bitset<8>(n) << std::endl;


}