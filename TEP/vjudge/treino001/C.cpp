#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    ll r1,c1,r2,c2; cin >> r1 >> c1 >> r2 >> c2; 
    
    if(r1 == r2 and c1 == c2)
        cout << 0 << endl;
    else if(r1+c1 == r2+c2 or r1-c1 == r2-c2 or (abs(r1 - r2) + abs(c1-c2)) <= 3)
        cout << 1 << endl;
    else if((r1+r2+c1+c2) % 2 == 0)
        cout << 2 << endl;
    else
        cout << 3 << endl;

    return 0;
}