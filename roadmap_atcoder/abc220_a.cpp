#include <bits/stdc++.h>


int find_multiple (int a, int b, int c) {

    int cons = 1;

    while(c <= b) {
        c = cons*c;
        if (c >= a && c <= b)
            return c;
        else
            cons++;
    }
              
    return -1;

}

int main(void){

    int a,b,c;
    std::cin >> a >> b >> c;

    std::cout << find_multiple(a,b,c) << std::endl;

}