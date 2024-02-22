#include <iostream>
#include <bitset>

int getIthBith(int bin, int i) {

    int mask = 1;
    mask=(mask<<i);

    return (bin & mask) > 0 ? 1 : 0;

}


int main(void) {

    int n, i;
    std::cout << "Digit a number in binary: ";
    std::cin >> n;
    std::cout << "Digit what bit of this number you want to know: ";
    std::cin >> i;

    std::cout << "The value're: " << getIthBith(n,i) << std::endl;


}