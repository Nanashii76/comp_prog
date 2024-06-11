#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isPalindrome(int x) {

    if(x < 0)
        return false;
    
    ll ans = 0;
    int aux = x;
    while(x) {
        ans = (10*ans)+(x%10);
        x /= 10;
    }

    if(ans > INT_MAX or ans < INT_MIN) return false;
    if(aux == ans) return true;

    return false;

}