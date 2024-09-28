#include <bits/stdc++.h>
using namespace std;

int isPrime(int N) {

    if(N <= 1)
        return 0;

    for(int i=2; i*i<=N; ++i)
        if(N%i==0)
            return 0;

    return 1;
}