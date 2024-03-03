#include <iostream>

/*
    Question 1:

    Print a triangle that follows this pattern (recursively)

    * * * * *
    * * * *
    * * *
    * *
    * 

*/

void triangle1(int n) {

    if (n == 0)
        return;
    
    for(int i = 0; i < n; ++i)
        std::cout << "*" << " ";
    std::cout << std::endl;

    triangle1(n-1);

}

// printing a normal triangle without "loop"
void triangle1_opt(int r, int c) {

    if(r == 0)
        return;

    if(c<r) {
        triangle1_opt(r,c+1);
        std::cout << "*" << " ";
    } else {
        triangle1_opt(r-1,0);
        std::cout << std::endl;
    }

}


int main(){

    triangle1(5);
    triangle1_opt(5,0);

}





