#include <iostream>
#include <bitset>

int countSetBits(int n) {

    int count = 0;
    while(n > 0) {
        count += (n&1);
        n = n >> 1;
    }

    return count;
}

int main(void) {

    // Basic problems envolving bitwise operations
    // 1.. Finding the unique number at a sequence
    // 2.. S compliment
    //3.. odd or even

    // Playing with bits, how many bits have (a to b)
    int a,b;
    int count = 0;
    std::cin >> a >> b;

    for(int i = a; i <= b; ++i)
        count += countSetBits(i);
    
    std::cout << count << std::endl;
         

}