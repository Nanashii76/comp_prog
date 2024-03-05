#include <iostream>

// i is the digit that want
// the order is right to left
int extract_digit(int n, int i) {

    if (i == 1)
        return n%10;

    return extract_digit(n/10,i-1);

}

int main(void){

    std::cout << extract_digit(1223456789,2);

}