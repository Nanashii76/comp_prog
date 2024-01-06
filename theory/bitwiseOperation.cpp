/*

Bitwise operations

-> And(&)
-> Or(|)
-> XOR(^) = result in 1 just when the values're different
-> NOT(~) = negation, changes 0 to 1 and 1 to 0; <2's compliment forn>
    0 is acutally -1 because the 2's compliment

-> left-shift(<<)

    # We multiply the number by the pass
    5 << 2 = 20 we move all the binary digits to the left

    5 << 2 = a << b -> a * 2^b;
    5 << 2 = 20 multiply the number for 4, 5 * 2^2 
    

-> right-shift(>>)

    # We divide the number by the pass

    10 >> 1 = 5 -> a / 2^b, 10 / 2^1
    20 >> 2 = 5

*/

#include <iostream>
using namespace std;

// A ordem começa do menos significativo até o mais, ou seja, da direita para esquerda
int getBit(int n, int i) {

    int mask = 1<<i;
    return (n&mask) > 0 ? 1 : 0;

}

int main(void) {

    // Checking if a number is odd or even with bitwise operators
    int x;
    cin >> x;

    if(x&1) // We use & because we're checking just the last bit
        cout << "Odd";
    else
        cout << "Even";
    
}