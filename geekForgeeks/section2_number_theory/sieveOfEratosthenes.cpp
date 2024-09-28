#include <bits/stdc++.h>
using namespace std;

vector<int> sieveOfEratosthenes(int N){

    vector<int> sieve(N,1);
    vector<int> ans;
    sieve[0] = sieve[1] = 0;

    for(int i = 2; i < N; ++i) {
        if(sieve[i] == 1) {
            ans.push_back(i);
            for(int j = i+i; j < N; j+=i)
                sieve[j] = 0;
        }
    }

    return ans;

}