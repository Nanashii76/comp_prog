#include <iostream>
/*
    Given a ladder containing N steps, you can take a jump of
    1,2 or 3 at each step. Find the number of ways to climb the 
    ladder

    input
    N=4

    output
    7
*/

int ladders(int n, int steps) {

    // basic case
    if(steps == n) 
        return 1;
    else if(steps > n)
        return 0;

    // recursion calls
    // we can jump one step
    int jump1 = ladders(n,steps+1);
    
    // we can jump two steps
    int jump2 = ladders(n,steps+2);

    // we can jump three steps 
    int jump3 = ladders(n,steps+3);

    
    // return the total
    return jump1+jump2+jump3;

}


int main(void) {

    int n;
    std::cin >> n;
    std::cout << ladders(n,0) << std::endl;

}



