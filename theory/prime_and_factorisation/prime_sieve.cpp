// Sieve of Erasthotenes
#include <iostream>
#include <vector>
#define N 1e6

typedef long long ll;

void primeSieve(std::vector<int> &sieve) {

    // Mark 1 and 0 as not prime
    sieve[1] = sieve[0] = 0;

    // Initially, mark all odd numbers as prime
    for(ll i = 3; i <= N; i+=2)
        sieve[i] = 1;

    // Start from 3 and mark all multiples of ith number
    for(ll i=3; i<=N; ++i) {

        if(sieve[i]) {
            for(ll j = i*i; j <=N; j=j+i) {
                // Marking j as not prime
                sieve[j] = 0;
            }
        }
    }
}



int main(void) {

    std::vector<int> primes(N,0); // fill constructor
    primeSieve(primes);

    for(ll i = 0; i < N; ++i)
        if(primes[i])
            std::cout << i << " ";
    std::cout << std::endl;

}