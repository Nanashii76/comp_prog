#include <iostream>
#include <bitset>

int countBits(int n) {

    int sum = 0;
    while(n != 0) {
        sum += (n&1);
        n = n>>1;
    }

    return sum;

}

int main(){

    int n;
    std::cin >> n;

    std::cout << countBits(n) << std::endl;

}