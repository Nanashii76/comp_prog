#include <iostream>
#include <vector>

#define N 1e6

typedef long long ll;

// Factorisation as prime numbers in O(n)
void factorise(int n) {

    for(int i = 2; i <= n; ++i) {
        if(n%i == 0) {
            int cnt = 0;
            while(n%i == 0) {
                n /= i;
                cnt++;
            }
            std::cout << i << "^" << cnt << ",";
        }
    }

    std::cout << std::endl;

}

// Optimized approach (O(sqrt(n)))
/*
Obs: Once N is reduced to a prime number, the only 
factor that number will be the number itself

If a number doesn't have any factor tilll sqrt(n)
then it is a prime number.

*/

void factorise2(int n) {

    for(int i = 2; i*i <= n; ++i) {
        if(n%i == 0) {
            int cnt = 0;
            while(n%i == 0) {
                cnt++;
                n /= i;
            }

            std::cout << i << "^" << cnt << ",";
        }
    }

    if(n!=1) {
        std::cout << n << "^" << 1 << std::endl;
        return;
    }

    std::cout << std::endl;

}

// Factorising using sieve of Erasthotenes O(log(n))
// Storing in the sieve the smallest prime factor of each number

void primeSieve(std::vector<ll> &sieve) {

    for(ll i=1; i <= N; ++i)
        sieve[i] = i;

    for(ll i = 2; i <= N; ++i) {
        // To discover non primes
        if(sieve[i] == i)
            for(ll j = i*i; j <= N; j+=i) 
                if(sieve[j] == j) {
                    sieve[j] = i;
                }
    }
}


std::vector<ll> factoriseWithSieve(std::vector<ll> &sieve, int n){

    std::vector<ll> factors;
    while(n != 1) {
        factors.push_back(sieve[n]);
        n /= sieve[n];
    }

    return factors;
}



int main(void) {

    ll n;
    std::vector<ll> primes(N,0);
    primeSieve(primes);

    std::cin >> n;

    std::vector<ll> factors = factoriseWithSieve(primes, n);
    for(auto x : factors)
        std::cout << x << " ";

    std::cout << std::endl;

}











