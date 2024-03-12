#include <iostream>
#include <bitset>

int setIthbit(int n, int i) {

    int mask = (1<<i);
    return (n|mask);

}

int main(void){

    int n, i;
    std::cin >> n >> i;

    std::cout << "Number(decimal) : " << n << std::endl;
    std::cout << "Number(binary) : " << std::bitset<4>(n) << std::endl;
    std::cout << "pposotion to change : " << i << std::endl;
    std::cout << "newNumber(binary) : " << std::bitset<4>(setIthbit(n,i)) << std::endl;
    std::cout << "newNumber(decimal) : " << setIthbit(n,i) << std::endl;
    
}