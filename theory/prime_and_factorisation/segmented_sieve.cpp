#include <iostream>
#include <vector>

#define N 100000

typedef long long ll;

int sieveArr[N+1]={0};
std::vector<int> primes;


void sieve(){

    for(ll i = 2; i <= N; ++i)
        if(sieveArr[i] == 0) {
            primes.push_back(i);
            for(ll j = i*i; j<= N; j+=i)
                sieveArr[j] = 1;
        }

}


int main() {

    // Precompute the sieve
    sieve();

    int t;
    std::cin >> t;

    while(t--) {
        int a,b;
        std::cin >> a >> b;

        std::vector<int> segmented(b-a+1, 0);

        for(auto p : primes) {
            // stop when p^2 > n
            if(p*p > b) 
                break;
            
            // finding the nearest starting point
            int start = (a/p)*p;

            // special case
            if(p>=a and p<=b)
                start = 2*p;


            for(int j = start; j <= b; j+=p) {
                if(j < a)
                    continue;
                // not prime    
                segmented[j-a] = 1;
            }
        }

        // primes stored as 0 in the segment
        for(int i = a; i <= b; ++i)
            if(segmented[i-a] == 0 && i != 1)
                std::cout << i << std::endl;
    }

    std::cout << std::endl;

    return EXIT_SUCCESS;
}



