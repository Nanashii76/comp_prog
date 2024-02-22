#include <iostream>
#include <bitset>

void clearIthbit(int &bin, int i) {
    int mask = (1<<i);
    bin &= ~(mask);
}


// This form takes O(n), we can do this in constant time
/*
int clearLastIbits(int &bin, int i) {
    int a=0;
    while(a < i) {
        clearIthbit(bin,a);
        a++;
    }

    return bin;
}
*/

// This form is constant 
int clearLastIbits(int &bin, int i) {
    int mask = (-1 << i);
    return bin &= mask;
}

int main(void) {

    int n, i;
    std::cin >> n >> i;
    n = clearLastIbits(n,i);
    
    std::cout << "dec: " << n << " bin: " << std::bitset<8>(n) << std::endl;
}