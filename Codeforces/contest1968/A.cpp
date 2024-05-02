#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    int result = min(a, b);
    while (result > 0) {
        if (a % result == 0 and b % result == 0) {
            break;
        }
        result--;
    }
 
    return result;
}


int main(){

    int n; cin >> n;
    while(n--) {
        int t; cin >> t;
        int maxGcd = 0, idx = 0;
        for(int i = 1; i < t; ++i) {
            if( gcd(t,i)+i > maxGcd ) {
                idx = i;
                maxGcd = gcd(t,i)+i;
            }
        }
        cout << idx << endl;
    }

    return 0;
}