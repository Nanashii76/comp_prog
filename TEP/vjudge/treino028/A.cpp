#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    ll n; cin >> n;
    ll count = ((n+1)*n)/2;

    cout << ( (count&1) ? "1" : "0" ) << endl;

}