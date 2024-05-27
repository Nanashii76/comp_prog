#include <bits/stdc++.h>
using namespace std;

int main(){

    int n,g,f,c; cin >> n >> g >> f >> c;
    int count = 0;
    while(g and f) {
        count++;
        g--,f--;
    }

    count+=c;
    cout << (count>n?n:count) << endl;

    return 0;
}