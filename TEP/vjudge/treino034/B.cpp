#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    
    int n, index = 1; cin >> n;
    ll count = 0;
    for(int i = 1; count < n; ++i) {
        index = i;
        count += i;
    }
        
    cout << index << endl;
    return 0;

}