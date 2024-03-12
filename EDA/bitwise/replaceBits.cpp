/*
    You're given two 32-bit numbers, N and M, ando two bit positions
    i and j.
    Write a method to set all bits between i and j in N equal to M.
    M (becomes a substring of N locationed at and starting at j)

    Example: 
    N = 10000000000
    M = 10101
    i = 2, j = 6
    output: 1001010100

*/
#include <iostream>
#include <bitset>


// First we've to clear a range number of bits
void clearBitsInRange(int &n, int i, int j) {
    
    int a = (-1)<<(j+1); 
    int b = (1<<i) - 1;
    int mask = a|b;
    n = n & mask;

}


// So, we can just make the or operation after left shifting M
void replace(int &n, int &m, int i, int j) {

    clearBitsInRange(n,i,j);
    int mask = (m<<i);
    n = n | mask;

}


int main(void) {

    int n = 15;
    int i = 1;
    int j = 3;
    int m = 2;


    replace(n,m,i,j);
    std::cout << std::bitset<8>(n) << std::endl;

}

