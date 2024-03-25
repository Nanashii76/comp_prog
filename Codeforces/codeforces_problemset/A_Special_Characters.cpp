#include <iostream>
#include <string>
#include <vector>

/*
    Explanation: We've to form a pair of letter that satisfy the input given;
    if the input is 3, so we've to form a pair of 3 letter, but it's impossible

    so, we just can form a pair with even numbers;
    to simplify, we can use AA and BB

*/


void solve(int n){

    // first, check if is a odd number
    if(n&1) {
        std::cout << "No" << std::endl;
        return;
    } 

    // case the number isn't odd
    std::cout << "Yes" << std::endl;
    int aux = 0; // creating a aux variable to store a even or a odd number
    while(n != 0) {
        if(aux&1) {
            std::cout << "AA"; // if the aux is even, add AA, case odd, add BB
            aux = 0;
        } else {
            std::cout << "BB";
            aux = 1;
        }
        n -= 2; // each time we add 2 letters
    }

    std::cout << std::endl;

}


int main(void) {

    int n; std::cin>>n;

    for(int i = 0; i < n; ++i) {
        int times; std::cin >> times;
        solve(times);
    }

}


