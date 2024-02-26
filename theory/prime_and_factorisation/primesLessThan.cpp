#include <iostream>
#include <vector>

#define N 5*(1e6)

typedef long long ll;


void primeSieve(std::vector<ll> &sieve) {

    sieve[1] = sieve[0] = 0;


    for(ll i = 2; i <= N; ++i)
        if(sieve[i])
            for(ll j = i*i; j <= N; j+=i)
                sieve[j] = 0;


}


ll primesLessThan(std::vector<ll> &v, ll n) {

    ll cout = 0;
    for(ll i = 2; i < n; ++i)
        if(v[i])
            cout++;

    return cout;

}


int main(){

    std::vector<ll> primes(N,1);
    primeSieve(primes);

    ll n;
    std::cin >> n;

    std::cout << primesLessThan(primes, n) << std::endl;
    
}













