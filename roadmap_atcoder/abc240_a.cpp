#include <bits/stdc++.h>

int main(void) {

    int a,b;
    std::cin >> a >> b;

    if (abs(a-b) != 1 && abs(a-b) != 9)
        std::cout << "No" << std::endl;
    else
        std::cout << "Yes" << std::endl;


}