#include <iostream>
#include <cmath>

int convertBinary(int n){

    int ans = 0, pot = 0;
    while(n != 0) {
        ans+=(n&1)*std::pow(10,pot);
        pot++;
        n = n>>1;
    }

    return ans;

}


int main(void){

    int n;
    std::cin >> n;

    std::cout << convertBinary(n) << std::endl;


}