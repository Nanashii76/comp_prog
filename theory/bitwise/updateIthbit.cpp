#include <iostream>
#include <bitset>

void clearIthbit(int &bin, int i) {
    int mask = (1<<i);
    bin &= ~(mask);
}


void updateIthbit(int &bin, int i, int v) {

    // Cleaning the Ith bit to create a mask to a value to update
    clearIthbit(bin,i);
    int mask=(v<<i);
    bin |= mask; // Sets the right value

}


int main(void) {

    int n, i, v;
    std::cin >> n >> i >> v;

    updateIthbit(n,i,v);

    std::cout << "dec: " << n << " bin: " << std::bitset<8>(n) << std::endl;

}