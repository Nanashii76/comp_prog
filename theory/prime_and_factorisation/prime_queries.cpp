#include <iostream>
#include <vector>
#define N 1e6

typedef long long ll;

void sieve(std::vector<ll> &sieve) {
    sieve[1] = sieve[0] = 0;

    for (ll i = 3; i <= N; i += 2)
        sieve[i] = 1;

    for (ll i = 3; i * i <= N; ++i) {
        if (sieve[i]) {
            for (ll j = i * i; j <= N; j += i) {
                sieve[j] = 0;
            }
        }
    }
}

ll countPrimes(std::vector<ll> &primesNum, ll a, ll b) {
    ll count = 0;

    for (ll i = a; i <= b; ++i) {
        if (primesNum[i])
            count++;
    }

    return count;
}

int main() {
    
    std::vector<ll> primes(N, 0);
    sieve(primes);

    ll n, a, b;
    std::cin >> n;

    for (ll i = 0; i < n; ++i) {
        std::cin >> a >> b;
        std::cout << countPrimes(primes, a, b) << std::endl;
    }

    return 0;
}