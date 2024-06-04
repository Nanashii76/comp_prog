#include <bits/stdc++.h>
using namespace std;

#define N 5*1e6
typedef long long ll;

vector<int> primeSieve() {

    vector<int> sieve(N,1);
    sieve[0] = sieve[1] = 0;

    for(ll i = 2; i <= N; ++i) {
        if(sieve[i])
            for(ll j = i*i; j <= N; j+=i)
                sieve[j] = 0;
    }

    return sieve;
}

int countPrimes(int n) {

    vector<int> primes = primeSieve();
    ll count = 0;
    for(ll i = 0; i < n; ++i)
        if(primes[i])
            count++;

    return count;

}

int main(){

    int n; cin >> n;
    cout << countPrimes(n) << endl;

    return 0;
}