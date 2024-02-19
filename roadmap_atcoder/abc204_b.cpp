#include <bits/stdc++.h>

int main(void) {

    int n, aux, sum = 0;

    std::cin >> n;

    for(int i = 0; i < n; ++i) {
        std::cin >> aux;
        if (aux > 10)
            sum += aux-10;
    }

    std::cout << sum << std::endl;

}