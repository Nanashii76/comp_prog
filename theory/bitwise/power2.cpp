#include <iostream>
#include <cmath>

/*

    To check if a number is a power of 2 using bitwise
    we have to compare n to n-1
    if (n & (n-1)) == 0, so the number is a power of two
    else isn't

*/


int power2(int n) {
    return ((n & (n-1)) == 0 ? 1 : 0);
}

// Have to solve to some issues (but isn't 100% correct)
int power4(int n) {
    return((power2(sqrt(n))) == 1 ? 1 : 0);
}


int main(void) {

    int n;
    std::cin >> n;

    if(power4(n) == 1)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;

}