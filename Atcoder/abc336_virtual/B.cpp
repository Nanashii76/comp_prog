#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string decimalToBinary(ll num){

    string res;
    while(num) {
        if(num&1)
            res +='1';
        else
            res += '0';
        num >>= 1;
    }

    return res;

}

ll countBits(string str) {

    ll i = 0, count = 0;
    while(str[i] != '1') {
        count++; i++;
    }

    return count;

}

int main(){

    ll n; cin >> n;
    
    if(n&1)
        cout << 0 << endl;
    else {        
        string bin = decimalToBinary(n);
        cout << countBits(bin) << endl;
    }
    
    return 0;
}