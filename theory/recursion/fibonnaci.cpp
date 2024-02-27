#include <iostream>

int fib(int n) {

    if(n == 0 or n == 1)
        return n;
    
    return fib(n-1) + fib(n-2);

}


int main(){

    std::cout << fib(5) << std::endl;

}