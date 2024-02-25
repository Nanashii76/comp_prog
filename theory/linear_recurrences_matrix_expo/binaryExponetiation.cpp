#include <iostream>

int binaryPower(int a, int b) {

    if (a == 0)
        return 0;

    int res = 1;
    while(b) {
        if(b&1)
            res *= a;
        a*=a;
        b = b>>1;
    }

    return res;

}


int main(void) {

    std::cout << binaryPower(2,10) << std::endl;


}












