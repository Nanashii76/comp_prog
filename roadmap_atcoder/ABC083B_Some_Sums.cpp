#include <bits/stdc++.h>

int digitsSum(int x) {

    int sum = 0;

    while (x != 0) {
        sum += x%10;
        x /= 10;
    }

    return sum;

}

int main(void) {

    int n, a ,b;
    std::cin >> n >> a >> b;

    int sum = 0;

    for(int i = 1; i <= n; ++i) 
        if(digitsSum(i) >= a && digitsSum(i) <= b) 
            sum += i;

    std::cout << sum << std::endl;

}