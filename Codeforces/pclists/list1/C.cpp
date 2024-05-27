#include <bits/stdc++.h>
using namespace std;

int main(){

    int n,a; cin >> n >> a;
    while(500 < n) {
        n-=500;
    }

    cout << ((n-a)<=0?"Sim":"Nao") << endl;

    return 0;
}