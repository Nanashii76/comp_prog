#include <bits/stdc++.h>

int main(void) {

    int a,b,c,x;
    std::cin >> a >> b >> c >> x;
    int tot = 0;

    // Analizyng until each coin become zero;
    for(int i = 0; i <= a; ++i)
        for(int j = 0; j <= b; ++j)
            for(int k = 0; k <= c; ++k) {
                int sum = 500*i + 100*j + 50*k;
                if(sum == x)
                    tot++;
            }

    std::cout << tot << std::endl;
                

}